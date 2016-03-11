// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ZoneManager.h"
#include "Point.h"
#include "WorldManager.generated.h"


UCLASS()
class CASHGENUE_API AWorldManager : public AActor
{
	GENERATED_BODY()

	// 1D array of the actual Zones
	TArray<AZoneManager*> ZonesMaster;

	AActor* currentPlayerPawn;
	UWorld* world;

	TQueue<int32, EQueueMode::Spsc> MyRegenQueue;

	int32 MyNumXZones;
	int32 MyNumYZones;
	float MyGridSize;
	int32 MyXUnits;
	int32 MyYUnits;
	float MyFloor;
	float MyPersistence;
	float MyFrequency;
	float MyAmplitude;
	int32 MyOctaves;
	int32 MySeed;
	
	

	void HandleZoneChange(FVector2D delta);

	int32 GetIdxfromXY(Point point) { return point.x * MyNumYZones + point.y; };
	Point GetXYfromIdx(int32 idx) { return Point(idx / MyNumYZones, idx % MyNumYZones); }

public:	
	// Sets default values for this actor's properties
	AWorldManager();
	int32 MyNumThreads;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "World Manager")
	void SpawnZones(AActor* aPlayerPawn, int32 aNumXZones, int32 aNumYZones, int32 aX, int32 aY, float aUnitSize, UMaterial* aMaterial, UMaterial* aWaterMaterial, float aFloorDepth, float aFloorHeight, float aWaterHeight, float aPersistence, float aFrequency, float aAmplitude, int32 aOctaves, int32 aRandomseed, int32 aNumThreads);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CashGen Manager")
		FVector2D currentPlayerZone;


};
