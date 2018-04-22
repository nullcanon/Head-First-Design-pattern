#include<iostream>
using namespace std;

/*******************��װ������Ϊ****************/
class FlyBehaviour
{
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehaviour
{
public:
	void fly()
	{
		cout << "I can fly^^!" << endl;
	}
};

class FlyNoWay : public FlyBehaviour
{
public:
	void fly()
	{
		cout << "I cant fly ��" << endl;
	}
};

class FlyRocketPowered :public FlyBehaviour
{
public:
	void fly()
	{
		cout << "I can fly with a rocket!" << endl;
	}
};

/*******************��װ���ɽ���Ϊ****************/
class QuackBehaviour
{
public:
	virtual void quack() = 0;
};

class Quack :public QuackBehaviour
{
public:
	void quack()
	{
		cout << "quack: gua gua gua" << endl;
	}
};

class Squack :public QuackBehaviour
{
public:
	void quack()
	{
		cout << "Squack: zhi zhi zhi" << endl;
	}
};

class MuteQuack :public QuackBehaviour
{
public:
	void quack()
	{
		cout << "Mute quack: ... ..." << endl;
	}
};

/*******************�ͻ�************************/
class Duck
{
public:
	void swim()
	{
		cout << "All ducks can swim" << endl;
	}
	void preformQuack()
	{
		_quackBehaviour->quack();
	}

	void preformFly()
	{
		_flyBehaviour->fly();
	}

	void setFlyBehaviour(FlyBehaviour* fb)
	{
		_flyBehaviour = fb;
	}
	void setQuackBehaviour(QuackBehaviour* qb)
	{
		_quackBehaviour = qb;
	}
public:
	virtual	void display() = 0;
private:
	FlyBehaviour* _flyBehaviour;
	QuackBehaviour* _quackBehaviour;
};

class RubberDuck :public Duck
{
public:
	void display()
	{
		cout << "I am a rubber duck" << endl;
	}
};

void test()
{
	Duck* d = new RubberDuck;
	d->setFlyBehaviour(new FlyNoWay);
	d->preformFly();

	d->setQuackBehaviour(new Squack);
	d->preformQuack();

	d->setFlyBehaviour(new FlyRocketPowered);
	d->preformFly();
}

int main()
{
	test();
	return 0;
}