// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "MyDragDropOperation.generated.h"

/**
 * 
 */
UCLASS()
class GITTESTPROJECT_API UMyDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UUserWidget* GrabWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D DragOffset; 
};
