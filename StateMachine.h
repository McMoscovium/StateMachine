#pragma once

#include "StateBase.h"
#include "IStateMachine.h"
#include <memory>
#include <iostream>


template <typename MachineType>
class StateMachine:
	public IStateMachine
{
protected:
	std::unique_ptr<StateBase<MachineType>> currentState;
	std::unique_ptr<StateBase<MachineType>> nextState;

	/// <summary>
	/// nextState‚ðcurrentState‚É‚¤‚Â‚·
	/// </summary>
	/// <returns>
	/// nextState!=null‚È‚çtrue
	/// </returns>
	bool changeState() {
		bool ret = nextState != nullptr;
		if (!currentState) {
			throw 1;
		}
		currentState->exit();
		currentState = std::move(nextState);
		nextState.reset();
		currentState->enter();
		return ret;
	}

public:
	StateMachine() :
		IStateMachine() {}
	virtual ~StateMachine() = default;

	void update() {
		if (nextState) {
			changeState();
		}
		if (currentState == nullptr) {
			std::cerr << "currentState==null‚Å‚·" << std::endl;
			return;
		}
		currentState->update();
	}
	bool setNextState(StateBase<MachineType>* next) {
		//false‚È‚çƒWƒƒƒ€ƒbƒeƒ‹
		bool ret = nextState == nullptr;
		nextState.reset(next);
		return ret;
	}
};