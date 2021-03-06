// Free to use, re-use, modify and share. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    void OpenDoor();
    void CloseDoor();

private:
    UPROPERTY(VisibleAnywhere)
    float OpenAngle = 90.f;

    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;

    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 0.4f;
    
    float TimeLastDoorOpen;
    
    //Pawn inherits from actor
    AActor* ActorThatOpens;

    //Owning Door
    AActor* Owner;


		
	
};
