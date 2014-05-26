#pragma once

#include "../Model.h"

#include <string>
#include <unordered_map>

class Action;

namespace models {

class Base : public Model {
	public:
		virtual ~Base();
	
		const Action* action(const char* identifier) const override;

		virtual Damage generateDamage(const Action* action, Actor* actor) const override;
		virtual Damage generateAutoAttackDamage(Actor* actor) const override;

		virtual Damage acceptDamage(const Damage& incoming, const Actor* actor) const override;

		virtual std::chrono::microseconds autoAttackInterval(const Actor* actor) const override;

		virtual double baseTickDamage(const Actor* source, const Aura* aura) const override;
		virtual double tickCriticalHitChance(const Actor* source) const override;

	protected:
		std::unordered_map<std::string, Action*> _actions;
		
		template <typename T>
		void _registerAction() {
			auto a = new T();
			_actions[a->identifier()] = a;
		}
		
		virtual DamageType _defaultDamageType() const = 0;
		
		virtual double _basePotencyMultiplier(const Actor* actor) const = 0;
		virtual double _baseAutoAttackDamage(const Actor* actor) const = 0;
};

}