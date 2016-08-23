// © 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "Watcher.h"

AWatcher::AWatcher(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EyeBlastParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Mobile/combat/SoulEater-Statue-StompBlast.SoulEater-Statue-StompBlast'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> BeamAudioObject(TEXT("SoundCue'/Game/Audio/Rocks/SoulEater_Statue_Jump_Cue.SoulEater_Statue_Jump_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> PreAtkAudioObject(TEXT("SoundCue'/Game/Audio/Rocks/SoulEater_Statue_Stomp_Cue.SoulEater_Statue_Stomp_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> DeathAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/Rock_Explo_Slowed02_L_Cue.Rock_Explo_Slowed02_L_Cue'"));
	static ConstructorHelpers::FObjectFinder<USoundCue> FlapAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/Rock_Explo_Slowed02_L_Cue.Rock_Explo_Slowed02_L_Cue'"));

	// Set Default Objects
	P_EyeBeamBlast = EyeBlastParticleObject.Object;
	S_BeamAudio = BeamAudioObject.Object;
	S_PreAtkAudio = PreAtkAudioObject.Object;
	S_DeathAudio = DeathAudioObject.Object;
	S_FlapAudio = FlapAudioObject.Object;

	// Create objects
	EyeBeamBlast = NewObject<UParticleSystemComponent>(this, TEXT("EyeBeamBlast"));
	BeamAudio = NewObject<UAudioComponent>(this, TEXT("BeamAudio"));
	PreAtkAudio = NewObject<UAudioComponent>(this, TEXT("PreAtkAudio"));
	DeathAudio = NewObject<UAudioComponent>(this, TEXT("DeathAudio"));
	FlapAudio = NewObject<UAudioComponent>(this, TEXT("FlapAudio"));

	// Configure Components
	EyeBeamBlast->Template = P_EyeBeamBlast;
	BeamAudio->Sound = S_BeamAudio;
	PreAtkAudio->Sound = S_PreAtkAudio;
	DeathAudio->Sound = S_DeathAudio;
	FlapAudio->Sound = S_FlapAudio;
}

// Called when the game starts or when spawned
void AWatcher::BeginPlay()
{
	Super::BeginPlay();

	//OnDeath.AddDynamic(this, &ADemonStatue::Death()); // bind the death fuction to the OnDeath event 
}

