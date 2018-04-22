#include<iostream>
#include<list>
using namespace std;
/*����֪ͨ�۲��ߵĹ��ýӿ�*/
class Observer
{
public:
	virtual void update(float temperture,float humidty,float pressure) = 0;
};

/*����ӿ�,����ʹ�ô˽ӿ�ע��Ϊ�۲���,����ע��*/
class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObserver() = 0;
};


/*�����չʾ�Ľӿ�*/
class DisplayElement
{
public:
	virtual void display() = 0;
};

/*��WeatherDataʵ��Subject�ӿ�*/
class WeatherData : public Subject
{
public:
	void registerObserver(Observer* o)
	{
		_obersvers.push_back(o);
	}
	void removeObserver(Observer* o)
	{
		_obersvers.remove(o);
	}
	void notifyObserver()
	{
		list<Observer*>::iterator it;
		for (it = _obersvers.begin(); it != _obersvers.end(); ++it)
			(*it)->update(_temperture,_humidty,_pressure);
	}

public:
	void measurementsChanged()
	{
		notifyObserver();
	}

	void setMeasurements(float temperture, float humidty, float pressure)
	{
		_temperture = temperture;
		_humidty = humidty;
		_pressure = pressure;
		measurementsChanged();
	}
	
private:
	list<Observer*> _obersvers;
	float _temperture;
	float _humidty;
	float _pressure;
};

/*�˲������ʾ��ǰ�۲�ֵ*/
class CurrentConditionsDisplay :public Observer, public DisplayElement
{
public:
	CurrentConditionsDisplay(WeatherData* weatherData)
	{
		weatherData->registerObserver(this);
	}

	void update(float temperature,float humidity,float pressure)
	{
		_temperature = temperature;
		_humidity = humidity;
		display();
	}
	void display()
	{
		cout << "Current conditions:" << endl;
		cout << "temperature:" << _temperature << endl;
		cout << "humidity:" << _humidity << endl;
	}
private:
	float _temperature;
	float _humidity;
};
/*�˲������ʾ��С���ƽ���۲�ֵ*/
class StattisticsDisplay : public Observer, public DisplayElement
{
public:
	StattisticsDisplay(WeatherData* weatherData)
	{
		weatherData->registerObserver(this);
	}

	void update(float temperature,float humidity,float pressure)
	{
		_temperature = temperature;
		_humidity = humidity;
		_pressure = pressure;
		display();
	}
	void display()
	{
		cout << "Stattistics:" << endl;
		cout << "temperature:" << _temperature << endl;
		cout << "humidity:" << _humidity << endl;
		cout << "pressure:" << _pressure << endl;
	}
private:
	float _temperature;
	float _humidity;
	float _pressure;
};

void test()
{
	WeatherData* pWeatherData = new WeatherData;
	CurrentConditionsDisplay* pCur = new CurrentConditionsDisplay(pWeatherData);
	StattisticsDisplay* pSta = new StattisticsDisplay(pWeatherData);
	
	pWeatherData->setMeasurements(10, 20, 30);
}

int main()
{
	test();
	return 0;
}
