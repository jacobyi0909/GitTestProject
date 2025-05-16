// Fill out your copyright notice in the Description page of Project Settings.


#include "DragAndDropWidget.h"

#include "MyDragDropOperation.h"

bool UDragAndDropWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
                                      UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	UMyDragDropOperation* op = Cast<UMyDragDropOperation>(InOperation);

	if (!IsValid(op))
	{
		UE_LOG(LogTemp, Warning, TEXT("os is Invalid"));
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("NativeOnDrop"));
	
	const FVector2D offset = InGeometry.AbsoluteToLocal(InDragDropEvent.GetScreenSpacePosition());
	const FVector2D offsetResult = offset - op->DragOffset;

	// op->GrabWidget->RemoveFromParent();
	// op->GrabWidget->AddToViewport();

	
	op->GrabWidget->SetVisibility(ESlateVisibility::Visible);
	op->GrabWidget->SetPositionInViewport(offsetResult, false);

	return true;
}
