// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSPlayer.h"

#include "MyDamageType.h"

// Sets default values
ATPSPlayer::ATPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATPSPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATPSPlayer::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	
	if (DamageEvent.DamageTypeClass == UMyDamageType::StaticClass())
	{
		
	}

	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);


}

