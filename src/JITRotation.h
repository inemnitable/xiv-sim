#pragma once

#include "Rotation.h"

#include <stdint.h>

class JITRotation : public Rotation {
	public:
		bool initializeWithFile(const char* filename);

		virtual const Action* nextAction(Actor* subject, const Actor* target) const override;

	private:
		const char*(*_jitNextAction)(Actor* subject, const Actor* target) = nullptr;

		static uint64_t ActorAuraCount(const Actor* actor, const char* identifier, const Actor* source);
		static double ActorCooldownRemaining(const Actor* actor, const char* identifier);
		static double ActorGlobalCooldownRemaining(const Actor* actor);
		static double ActorAuraTimeRemaining(const Actor* actor, const char* identifier, const Actor* source);
		static Actor* ActorPet(Actor* actor);
		static uint64_t ActorTP(const Actor* actor);
		static uint64_t ActorMP(const Actor* actor);
		static double ActorGlobalCooldown(const Actor* actor);
		static double ActorTime(const Actor* actor);
		static void ActorRemoveAura(Actor* actor, const char* identifier, const Actor* source);
		static uint8_t ActionIsReady(const Actor* actor, const char* identifier);
		static void ActorCommand(Actor* actor, const char* identifier);
		static void ActorStopAutoAttack(Actor* actor);
};
