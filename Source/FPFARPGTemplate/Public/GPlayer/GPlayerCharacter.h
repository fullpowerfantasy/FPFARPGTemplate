// Copyright (c) 2023 Full Power Fantasy LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "CoreMinimal.h"
#include "GBaseClasses/GCharacter.h"
#include "AbilitySystemInterface.h"
#include "GPlayerCharacter.generated.h"

UCLASS()
class FPFARPGTEMPLATE_API AGPlayerCharacter : public AGCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }

	// CharacterInputComponent handles all input-related functionality such as movement and attacks
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterInputComponent* CharacterInputComponent;

	// Custom camera component for top-down view
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	class UGCameraComponent* CameraComponent;

	// InventoryComponent handles the player's inventory, gold, and item management
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGInventoryComponent* InventoryComponent;

	// CharacterStatsComponent handles character stats, health, leveling, and skill points
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterStatsComponent* CharacterStatsComponent;

	// AbilityComponent manages the player's abilities and their respective cooldowns
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGAbilityComponent* AbilityComponent;

	// DialogueComponent handles dialogue interactions with NPCs and quest-related functionality
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGDialogueComponent* DialogueComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterProgressionComponent* CharacterProgressionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterInfoComponent* CharacterInfoComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	class UAbilitySystemComponent* AbilitySystemComponent;

};
