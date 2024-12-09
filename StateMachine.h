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
	/// nextState��currentState�ɂ���
	/// </summary>
	/// <returns>
	/// nextState!=null�Ȃ�true
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
			std::cerr << "currentState==null�ł�" << std::endl;
			return;
		}
		currentState->update();
	}
	bool setNextState(StateBase<MachineType>* next) {
		//false�Ȃ�W�����b�e��
		bool ret = nextState == nullptr;
		nextState.reset(next);
		return ret;
	}
};