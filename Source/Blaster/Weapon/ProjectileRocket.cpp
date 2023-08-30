// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileRocket.h"

void AProjectileRocket::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
}
