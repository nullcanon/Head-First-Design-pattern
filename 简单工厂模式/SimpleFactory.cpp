//简单工厂模式
#include<iostream>
#include<string>
using namespace std;

class Pizza
{
public:
	virtual void prepare() = 0;
	virtual void bake() = 0;
	virtual void cut() = 0;
	virtual void box() = 0;
};

class CheesePizza :public Pizza
{
public:
	CheesePizza()
		:_name("Cheese pizza")
	{}
	void prepare()
	{
		cout<<_name<<"prepare" << endl;
	}
	void bake()
	{
		cout <<_name<< "bake" << endl;
	}
	void cut()
	{
		cout << _name<<"cut" << endl;
	}
	void box()
	{
		cout << _name<<"box" << endl;
	}
private:
	string _name;
};

class VeggiePizza :public Pizza
{
public:
	VeggiePizza()
		:_name("Veggie pizza")
	{}
	void prepare()
	{
		cout<<_name<<"prepare" << endl;
	}
	void bake()
	{
		cout<<_name<< "bake" << endl;
	}
	void cut()
	{
		cout<< _name<<"cut" << endl;
	}
	void box()
	{
		cout<< _name<<"box" << endl;
	}
private:
	string _name;
};

//ClamPizza
//PepperoniPizza
//...

class SimplePizzaFactoy
{
public:
	Pizza* createPizza(string type)
	{
		if (type == "Cheese")
			return (new CheesePizza);
		else if (type == "Veggie")
			return (new VeggiePizza);
		else
			return NULL;
	}
};


class PizzaStore
{
public:
	PizzaStore(SimplePizzaFactoy* spf)
		:_simplePizzaFactory(spf)
	{}
	

	Pizza* orderPizza(string type)
	{
		Pizza* pizza = _simplePizzaFactory->createPizza(type);
		if (NULL == pizza)
			return NULL;
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		return pizza;
	}
private:
	SimplePizzaFactoy* _simplePizzaFactory;
};

int main()
{
	SimplePizzaFactoy* spf = new SimplePizzaFactoy();
	PizzaStore ps = PizzaStore(spf);
	ps.orderPizza("Cheese");
	ps.orderPizza("Veggie");
	return 0;
}