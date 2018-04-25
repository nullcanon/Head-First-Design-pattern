#include<string>
#include<iostream>

using namespace std;

/*****************���*******************/
class Beverage
{
public:
	virtual double Cost() = 0;
	virtual string GetDescription()
	{
		return _description;
	}

	string _description;
};

/*�������*/
class HouseBlend :public Beverage
{
public:
	HouseBlend()
	{
		_description = "HouseBlend";
	}
	double Cost()
	{
		return 0.88;
	}
};
class DarkRoast :public Beverage
{
public:
	DarkRoast()
	{
		_description = "DarkRoast";
	}
	double Cost()
	{
		return 1.23;
	}
};
class Espresso :public Beverage
{
public:
	Espresso()
	{
		_description = "Espresso";
	}
	double Cost()
	{
		return 2.01;
	}
};
class Decaf : public Beverage
{
public:
	Decaf()
	{
		_description = "Decaf";
	}
	double Cost()
	{
		return 0.99;
	}
};
/******************װ����*****************/
class CondimentDecorator : public Beverage
{
public:
	virtual string GetDescription() = 0;
};

/*����װ����*/
class Milk :public CondimentDecorator
{
public:
	Milk(Beverage* beverage)
		:_beverage(beverage)
	{}
	string GetDescription()
	{
		return (_beverage->GetDescription() + " Milk");
	}
	double Cost()
	{
		return (_beverage->Cost() + 0.5);
	}
private:
	Beverage *_beverage;
};

class whip :public CondimentDecorator
{
public:
	whip(Beverage* beverage)
		:_beverage(beverage)
	{}
	string GetDescription()
	{
		return (_beverage->GetDescription() + " whip");
	}
	double Cost()
	{
		return (_beverage->Cost() + 0.9);
	}
private:
	Beverage *_beverage;
};

class Mocha :public CondimentDecorator
{
public:
	Mocha(Beverage* beverage)
		:_beverage(beverage)
	{}
	string GetDescription()
	{
		return (_beverage->GetDescription() + " Mocha");
	}
	double Cost()
	{
		return (_beverage->Cost() + 0.6);
	}
private:
	Beverage *_beverage;
};

class Soy :public CondimentDecorator
{
public:
	Soy(Beverage* beverage)
		:_beverage(beverage)
	{}
	string GetDescription()
	{
		return (_beverage->GetDescription() + " Soy");
	}
	double Cost()
	{
		return (_beverage->Cost() + 0.3);
	}
private:
	Beverage *_beverage;
};

void test()
{
	//ֻ��һ��Ũ����
	Beverage* beverage = new Espresso;
	cout << beverage->GetDescription() << " $" << beverage->Cost() << endl;

	//һ����ɫ�決+Ħ��+2*����
	Beverage* beverage2 = new DarkRoast;
	beverage2 = new Mocha(beverage2);
	beverage2 = new whip(beverage2);
	beverage2 = new whip(beverage2);
	cout << beverage2->GetDescription() << " $" << beverage2->Cost() << endl;
}

int main()
{
	test();
	return 0;
}