// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "Terminal.generated.h"

UCLASS()
class GROUPPROJECT_API ATerminal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerminal();
	FString TerminalText;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "TextRenderer")
	UTextRenderComponent* TerminalRender;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PrintLine(const FString& Line) const;
	void PrintLine(const TCHAR* Line) const; // Avoid template for this case.
	template<SIZE_T N, typename ...Types>
	void PrintLine(const TCHAR (&Fmt)[N], Types... Args) const
	{
		PrintLine(FString::Printf(Fmt, Args...));
	}
	void ClearScreen() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	class  UTerminal* Terminal;
};
