// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APortal::APortal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();

	CaptureCamera = GetComponentByClass<USceneCaptureComponent2D>();
	if (CaptureCamera)
	{
		CaptureCamera->bEnableClipPlane = true;
		APawn* player = GetWorld()->GetFirstPlayerController()->GetPawn();
		TArray<AActor*> hiddenActors;
		hiddenActors.Add(player);
		CaptureCamera->HiddenActors = hiddenActors;
	}
}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APortal::SetClipPlane(FVector base, FVector normal)
{
	CaptureCamera->ClipPlaneBase = base + normal * -1.5f;
	CaptureCamera->ClipPlaneNormal = normal;
}

void APortal::UpdateRotation_Implementation(class APortal* otherPortal)
{
	
}

void APortal::UpdateLocation_Implementation(class APortal* otherPortal)
{
	FVector camLoc = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();

	FVector localLoc = GetActorTransform().InverseTransformPositionNoScale(camLoc);

	FVector flippedLoc(-localLoc.X, -localLoc.Y, localLoc.Z);

	FVector newLoc = otherPortal->GetActorTransform().TransformPositionNoScale(flippedLoc);

	otherPortal->CaptureCamera->SetWorldLocation(newLoc);
}
