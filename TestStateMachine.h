#pragma once
#include "StateMachine.h"
#include "StateBase.h"
#include <iostream>



class TestStateMachine :
    public StateMachine<TestStateMachine>
{
private:
    class Neutral:
        public StateBase<TestStateMachine>
    {
    private:
    public:
        Neutral(TestStateMachine& machine):
            StateBase<TestStateMachine>(machine){ }
        ~Neutral() = default;

        void enter()override;
        void update()override;
        void exit() override;
    };
    class Up :
        public StateBase<TestStateMachine>
    {
    private:
    public:
        Up(TestStateMachine& machine) :
            StateBase<TestStateMachine>(machine)            
        {}
        ~Up() = default;

        void enter()override;
        void update()override;
        void exit() override;
    };
    class Down :
        public StateBase<TestStateMachine>
    {
    private:
    public:
        Down(TestStateMachine& machine) :
            StateBase<TestStateMachine>(machine) {}
        ~Down() = default;

        void enter()override;
        void update()override;
        void exit() override;
    };
    class Left :
        public StateBase<TestStateMachine>
    {
    private:
    public:
        Left(TestStateMachine& machine) :
            StateBase<TestStateMachine>(machine) {}
        ~Left() = default;

        void enter()override;
        void update()override;
        void exit() override;
    };
    class Right :
        public StateBase<TestStateMachine>
    {
    private:
    public:
        Right(TestStateMachine& machine) :
            StateBase<TestStateMachine>(machine) {}
        ~Right() = default;

        void enter()override;
        void update()override;
        void exit() override;
    };
public:
    TestStateMachine() :
        StateMachine()
    {
        currentState.reset(new Neutral(*this));
    }
    virtual ~TestStateMachine() = default;
};

void TestStateMachine::Neutral::enter() {
        std::system("cls");
        std::cout << "entring Neutral state" << std::endl;
        std::system("pause");
}

void TestStateMachine::Neutral::update() {
    //�X�N���[�����N���[�i�b�v
    std::system("cls");
    //���͎w��
    std::cout << "w:up" << std::endl;
    std::cout << "a:left" << std::endl;
    std::cout << "s:down" << std::endl;
    std::cout << "d:right" << std::endl;
    std::cout << std::endl;
    std::cout << "�ǂ�ɂ��܂����H" << std::endl;
    //���͂��󂯎��
    std::string in;
    std::cin >> in;
    //���͂ɂ���ăX�e�[�g�ύX
    if (in == "w") {
        machine.setNextState(new Up(machine));
    }
    else if (in == "a") {
        machine.setNextState(new Left(machine));
    }
    else if (in == "s") {
        machine.setNextState(new Right(machine));
    }
    else if (in == "d") {
        machine.setNextState(new Down(machine));
    }
    else {
        std::cout << "���̕����͂Ȃ���" << std::endl;
        std::system("pause");
    }
}
    
void TestStateMachine::Neutral::exit(){
        std::system("cls");
        std::cout << "exitting Neutral state" << std::endl;
        std::system("pause");
}


void TestStateMachine::Up::enter(){
        std::system("cls");
        std::cout << "entring Up state" << std::endl;
        std::system("pause");
}

void TestStateMachine::Up::update(){
    //�X�N���[�����N���[�i�b�v
    std::system("cls");
    //���͎w��
    std::cout << "w:up" << std::endl;
    std::cout << "a:left" << std::endl;
    std::cout << "s:down" << std::endl;
    std::cout << "d:right" << std::endl;
    std::cout << std::endl;
    std::cout << "�ǂ�ɂ��܂����H" << std::endl;
    //���͂��󂯎��
    std::string in;
    std::cin >> in;
    //���͂ɂ���ăX�e�[�g�ύX
    if (in == "w") {
        std::cout << "���ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "a") {
        std::cout << "��ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "s") {
        machine.setNextState(new Neutral(machine));
    }
    else if (in == "d") {
        std::cout << "�E�ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else {
        std::cout << "���̕����͂Ȃ���" << std::endl;
        std::system("pause");
    }
}
void TestStateMachine::Up::exit() {
    std::system("cls");
    std::cout << "exitting Up state" << std::endl;
    std::system("pause");
}


void TestStateMachine::Down::enter(){
    std::system("cls");
    std::cout << "entring Down state" << std::endl;
    std::system("pause");
}
void TestStateMachine::Down::update() {
    //�X�N���[�����N���[�i�b�v
    std::system("cls");
    //���͎w��
    std::cout << "w:up" << std::endl;
    std::cout << "a:left" << std::endl;
    std::cout << "s:down" << std::endl;
    std::cout << "d:right" << std::endl;
    std::cout << std::endl;
    std::cout << "�ǂ�ɂ��܂����H" << std::endl;
    //���͂��󂯎��
    std::string in;
    std::cin >> in;
    //���͂ɂ���ăX�e�[�g�ύX
    if (in == "w") {
        std::cout << "��ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "a") {
        machine.setNextState(new Neutral(machine));
    }
    else if (in == "s") {
        std::cout << "���ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "d") {
        std::cout << "�E�ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else {
        std::cout << "���̕����͂Ȃ���" << std::endl;
        std::system("pause");
    }
}
void TestStateMachine::Down::exit() {
    std::system("cls");
    std::cout << "exitting Down state" << std::endl;
    std::system("pause");
}

void TestStateMachine::Left::enter() {
    std::system("cls");
    std::cout << "entring Left state" << std::endl;
    std::system("pause");
}
void TestStateMachine::Left::update() {
    //�X�N���[�����N���[�i�b�v
    std::system("cls");
    //���͎w��
    std::cout << "w:up" << std::endl;
    std::cout << "a:left" << std::endl;
    std::cout << "s:down" << std::endl;
    std::cout << "d:right" << std::endl;
    std::cout << std::endl;
    std::cout << "�ǂ�ɂ��܂����H" << std::endl;
    //���͂��󂯎��
    std::string in;
    std::cin >> in;
    //���͂ɂ���ăX�e�[�g�ύX
    if (in == "w") {
        std::cout << "��ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "a") {
        std::cout << "���ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "s") {
        std::cout << "���ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "d") {
        machine.setNextState(new Neutral(machine));
    }
    else {
        std::cout << "���̕����͂Ȃ���" << std::endl;
        std::system("pause");
    }
}
void TestStateMachine::Left::exit() {
    std::system("cls");
    std::cout << "exitting Left state" << std::endl;
    std::system("pause");
}

void TestStateMachine::Right::enter() {
    std::system("cls");
    std::cout << "entring Right state" << std::endl;
    std::system("pause");
}
void TestStateMachine::Right::update() {
    //�X�N���[�����N���[�i�b�v
    std::system("cls");
    //���͎w��
    std::cout << "w:up" << std::endl;
    std::cout << "a:left" << std::endl;
    std::cout << "s:down" << std::endl;
    std::cout << "d:right" << std::endl;
    std::cout << std::endl;
    std::cout << "�ǂ�ɂ��܂����H" << std::endl;
    //���͂��󂯎��
    std::string in;
    std::cin >> in;
    //���͂ɂ���ăX�e�[�g�ύX
    if (in == "w") {
        std::cout << "��ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "a") {
        machine.setNextState(new Neutral(machine));
    }
    else if (in == "s") {
        std::cout << "���ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else if (in == "d") {
        std::cout << "�E�ɂ͂����Ȃ���" << std::endl;
        std::system("pause");
    }
    else {
        std::cout << "���̕����͂Ȃ���" << std::endl;
        std::system("pause");
    }
}
void TestStateMachine::Right::exit(){
    std::system("cls");
    std::cout << "exitting Right state" << std::endl;
    std::system("pause");
}