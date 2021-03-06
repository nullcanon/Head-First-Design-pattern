刚学习完C++的语法时，我懂得了继承、多态，会封装一些类，写一些简单的程序，但是代码冗杂，可读性、可维护性差让我甚是沮丧。
接触到了设计模式，才明白语法只不过是开始，一些巧妙的设计会增加代码的可复用性、可维护性，设计出好的代码结构，会有一种自己是艺术家的错觉。

博观而约取，厚积而勃发。写程序如同写文章一样，只有学习到了不同的手法，才能在不同的场景中做到游刃有余。
遂从《Head First 设计模式》里面学习一些OO设计模式记录于此。

 - **策略模式**
 
 策略模式定义了算法族，分别封装起来，让他们之间可以相互替换，此模式让算法的变化独立于使用算法的客户。

原则：①封装变化　②多用组合，少用继承　③准对接口编程，不针对实现编程

![](https://github.com/nullcanon/Head-First-Design-pattern/blob/master/%E7%AD%96%E7%95%A5%E6%A8%A1%E5%BC%8F/%E7%AD%96%E7%95%A5%E6%A8%A1%E5%BC%8F.jpg)

 - **观察者模式**
 
 在对象之间定义一对多的关系，这样当一个对象改变状态，依赖它的对象会收到通知，并自动更新。
 
 原则：为交互对象之间的松耦合设计而努力
 
 ![](https://github.com/nullcanon/Head-First-Design-pattern/blob/master/%E8%A7%82%E5%AF%9F%E8%80%85%E6%A8%A1%E5%BC%8F/%E8%A7%82%E5%AF%9F%E8%80%85%E6%A8%A1%E5%BC%8F.jpg)

 - **装饰者模式**

动态的将责任附加到对象上。想要拓展功能，装饰者提供有别于继承的另一种选择。

原则：对拓展开放，对修改关闭

![](https://github.com/nullcanon/Head-First-Design-pattern/blob/master/%E8%A3%85%E9%A5%B0%E8%80%85%E6%A8%A1%E5%BC%8F/%E8%A3%85%E9%A5%B0%E8%80%85%E6%A8%A1%E5%BC%8F.jpg)

 - **简单工厂模式**
 
![](https://github.com/nullcanon/Head-First-Design-pattern/blob/master/%E7%AE%80%E5%8D%95%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F/UML.jpg)

 ###**待续**...
