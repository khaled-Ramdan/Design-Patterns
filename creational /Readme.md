# Singleton 
The Singleton design pattern is one of the most widely used design patterns in software engineering. It is a creational design pattern, which means it deals with object creation mechanisms. The Singleton pattern ensures that a class has only one instance and provides a global point of access to that instance.

Here's how the Singleton pattern typically works:

1. Private Constructor: The Singleton class has a private constructor, which prevents direct instantiation of the class from outside.

2. Private Instance: Within the Singleton class, there is a private static instance of the class itself.

3. Public Access Method: The Singleton class provides a public static method (often named `getInstance()`) that allows clients to access the single instance of the class.

4. Lazy or Eager Initialization: Depending on the implementation, the single instance can be created either lazily (only when `getInstance()` is called for the first time) or eagerly (at the time of class loading).

5. Thread-Safe Implementation (optional): In multi-threaded environments, it's important to ensure that only one instance is created even when multiple threads access the `getInstance()` method simultaneously. This can be achieved through synchronization mechanisms or by using a thread-safe initialization method.

Here's a simple example of a Singleton in Java:

```java
public class Singleton {
    private static Singleton instance;

    // Private constructor to prevent direct instantiation
    private Singleton() {
    }

    // Public static method to get the single instance
    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}
```

In this example, the `Singleton` class ensures that there is only one instance created when `getInstance()` is called for the first time. Subsequent calls to `getInstance()` return the same instance.

Advantages of the Singleton pattern:

1. **Global Point of Access:** It provides a single point of access to the instance, making it easy to manage and control the object's lifecycle.

2. **Lazy Initialization:** You can defer the creation of the instance until it is actually needed, which can be more efficient.

3. **Resource Sharing:** It allows you to share resources, configurations, or data across the application.

However, it's important to use the Singleton pattern judiciously, as it can introduce global state, which can make the code less modular and harder to test. Also, in multi-threaded environments, you need to ensure that the Singleton instance is created safely to avoid race conditions and ensure thread-safety.

# Factory method

The Factory Method design pattern is a creational pattern in software design that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created. This pattern promotes loose coupling between the creator and the objects it creates, making it easier to extend and maintain a system.

Here's an explanation of the key components and the typical structure of the Factory Method pattern:

1. **Creator:** This is an abstract class or interface that defines a method, often called the "factory method." The factory method is responsible for creating objects, but it doesn't specify the exact type of objects to be created. Instead, it declares the method signature, and concrete subclasses are responsible for implementing it.

2. **Concrete Creator:** Subclasses of the Creator class implement the factory method to create specific types of objects. Each concrete creator can produce a different kind of product.

3. **Product:** This is an abstract class or interface representing the objects that the factory method creates. The product can have common attributes and behaviors that all concrete products share.

4. **Concrete Product:** Subclasses of the Product class represent specific types of objects that the factory method produces. Each concrete product class implements its unique functionality.

Here's a step-by-step breakdown of how the Factory Method pattern works:

1. A client code (e.g., the main application) calls the factory method on a Creator object to create a product.

2. The Creator's factory method is responsible for deciding which Concrete Product class to instantiate. This decision can be based on various factors, such as configuration, user input, or other runtime conditions.

3. The factory method creates an instance of the Concrete Product and returns it as an abstract Product type to the client code.

4. The client code can then use the Product object without needing to know the specific Concrete Product class that was created.

The Factory Method pattern allows for easy extensibility. When you need to add a new type of product, you can simply create a new Concrete Product class and a corresponding Concrete Creator subclass, without modifying existing code. This promotes the Open-Closed Principle (open for extension, closed for modification) in software design.

In summary, the Factory Method design pattern abstracts the process of object creation, allowing subclasses to decide which specific class to instantiate. It enhances flexibility, maintainability, and scalability in software systems by avoiding tight coupling between the creator and the created objects.
``` cpp
#include <iostream>
#include <memory>

// Abstract Product: Shape
class Shape {
public:
    virtual void draw() = 0;
};

// Concrete Products: Circle and Rectangle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

// Abstract Creator: ShapeFactory
class ShapeFactory {
public:
    virtual std::unique_ptr<Shape> createShape() = 0;
};

// Concrete Creators: CircleFactory and RectangleFactory
class CircleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() override {
        return std::make_unique<Circle>();
    }
};

class RectangleFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() override {
        return std::make_unique<Rectangle>();
    }
};

int main() {
    // Client code
    std::unique_ptr<ShapeFactory> circleFactory = std::make_unique<CircleFactory>();
    std::unique_ptr<Shape> circle = circleFactory->createShape();
    circle->draw();

    std::unique_ptr<ShapeFactory> rectangleFactory = std::make_unique<RectangleFactory>();
    std::unique_ptr<Shape> rectangle = rectangleFactory->createShape();
    rectangle->draw();

    return 0;
}
```
