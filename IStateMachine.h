#pragma once

#include <concepts>

class IStateMachine
{
public:
	virtual ~IStateMachine() = default;
	virtual void update() = 0;
};

template <typename T>
concept DerivedOfIStateMachine = std::derived_from<T, IStateMachine>;