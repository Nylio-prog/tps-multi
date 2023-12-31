// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BLASTER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	float Damage = 20.f;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactParticles;

	UPROPERTY(EditAnywhere)
	class USoundCue* ImpactSound;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* TrailSystem;

	UPROPERTY()
	class UNiagaraComponent* TrailSystemComponent;

	void SpawnTrailSystem();
	void StartDestroyTimer();
	void DestroyTimerFinished();
	void ExplodeDamage();

	UPROPERTY(EditAnywhere)
	float DamageInnerRadius = 200.f;

	UPROPERTY(EditAnywhere)
	float DamageOuterRadius = 700.f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ProjectileMesh;
private:
	

	UPROPERTY(EditAnywhere)
	UParticleSystem* Tracer;

	class UParticleSystemComponent* TracerComponent;

	/**
	* Particles and sound
	*/
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* PlayerImpactParticles;

	UPROPERTY(EditAnywhere)
	USoundCue* PlayerImpactSound;

	UPROPERTY(EditAnywhere)
	UParticleSystem* NonPlayerImpactParticles;

	UPROPERTY(EditAnywhere)
	USoundCue* NonPlayerImpactSound;

	FTimerHandle DestroyTimer;
	UPROPERTY(EditAnywhere)
	float DestroyTime = 3.f;

public:	


};
