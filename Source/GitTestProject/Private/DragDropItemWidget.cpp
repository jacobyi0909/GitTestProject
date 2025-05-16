// Fill out your copyright notice in the Description page of Project Settings.


#include "DragDropItemWidget.h"


#include "MyDragDropOperation.h"

void UDragDropItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

FReply UDragDropItemWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("NativeOnMouseButtonDown"));
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	return CustomDetectDrag(InMouseEvent, this, EKeys::LeftMouseButton);
}

void UDragDropItemWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	UE_LOG(LogTemp, Warning, TEXT("NativeOnDragDetected"));
	
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);

	UMyDragDropOperation* op = NewObject<UMyDragDropOperation>();
	this->SetVisibility(ESlateVisibility::HitTestInvisible);

	op->GrabWidget = this;
	op->DragOffset = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());

	op->DefaultDragVisual = this;
	op->Pivot = EDragPivot::MouseDown;

	OutOperation = op;
}

void UDragDropItemWidget::NativeOnDragLeave(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	Super::NativeOnDragLeave(InDragDropEvent, InOperation);	
}

FReply UDragDropItemWidget::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent)
{
	//Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);

	FReply reply = NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	return reply;
}

FReply UDragDropItemWidget::CustomDetectDrag(const FPointerEvent& InMouseEvent, UWidget* WidgetDetectingDrag,
                                            FKey DragKey)
{
	UE_LOG(LogTemp, Warning, TEXT("CustomDetectDrag"));
	
	if ( InMouseEvent.GetEffectingButton() == DragKey /*|| PointerEvent.IsTouchEvent()*/ )
	{
		FEventReply Reply;
		Reply.NativeReply = FReply::Handled();
		
		if ( WidgetDetectingDrag )
		{
			TSharedPtr<SWidget> SlateWidgetDetectingDrag = WidgetDetectingDrag->GetCachedWidget();
			if ( SlateWidgetDetectingDrag.IsValid() )
			{
				Reply.NativeReply = Reply.NativeReply.DetectDrag(SlateWidgetDetectingDrag.ToSharedRef(), DragKey);
				return Reply.NativeReply;
			}
		}
	}

	return FReply::Unhandled();
}
