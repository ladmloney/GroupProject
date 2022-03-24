// Fill out your copyright notice in the Description page of Project Settings.


#include "Terminal.h"

#include <ostream>

#include "Components/TextRenderComponent.h"
// Sets default values
ATerminal::ATerminal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	//TerminalRender = GetOwner()->FindComponentByClass<UTextRenderComponent>();
}

// Called when the game starts or when spawned
void ATerminal::BeginPlay()
{
	Super::BeginPlay();
	TerminalRender = FindComponentByClass<UTextRenderComponent>();
	TerminalText = "Hello World \nHello";
	TerminalRender->SetText(FText::FromString(TerminalText));
	TerminalRender->SetTextRenderColor(FColor::Green);
	TerminalRender->SetXScale(0.2f);
	TerminalRender->SetYScale(0.2f);
	
	
}

// Called every frame
void ATerminal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

