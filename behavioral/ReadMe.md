# Command
The Command Design Pattern is a behavioral design pattern that encapsulates a request as an object, thereby allowing for parameterization of clients with different requests, queuing of requests, and logging of the requests. It also provides a way to undo operations. This pattern decouples the sender and receiver of a request by allowing different objects to handle the request.

Here are the main components of the Command Pattern:

1. **Command:** This is an interface or an abstract class that declares a method like `execute()` which concrete commands will implement. It usually holds a reference to the receiver (the object that performs the actual action).

2. **ConcreteCommand:** These are classes that implement the `Command` interface. They encapsulate a specific action and hold a reference to the receiver object.

3. **Invoker:** This class holds a command and can execute it when needed. It acts as a request sender.

4. **Receiver:** This class performs the actual work associated with a command. It knows how to carry out the action.

5. **Client:** Creates a command and associates it with the receiver. The client also associates the command with the invoker.

Here's a simplified example in C++:

```cpp
#include <iostream>
#include <vector>

class Command {
public:
    virtual void execute() = 0;
};

class Light {
public:
    void turnOn() {
        std::cout << "Light is on." << std::endl;
    }
    void turnOff() {
        std::cout << "Light is off." << std::endl;
    }
};

class LightOnCommand : public Command {
private:
    Light& light;

public:
    LightOnCommand(Light& l) : light(l) {}

    void execute() override {
        light.turnOn();
    }
};

class LightOffCommand : public Command {
private:
    Light& light;

public:
    LightOffCommand(Light& l) : light(l) {}

    void execute() override {
        light.turnOff();
    }
};

class RemoteControl {
private:
    Command* command;

public:
    void setCommand(Command* c) {
        command = c;
    }

    void pressButton() {
        command->execute();
    }
};

int main() {
    Light light;
    LightOnCommand onCmd(light);
    LightOffCommand offCmd(light);

    RemoteControl remote;

    remote.setCommand(&onCmd);
    remote.pressButton(); // Turns on the light

    remote.setCommand(&offCmd);
    remote.pressButton(); // Turns off the light

    return 0;
}
```

In this example, the `Command` pattern allows the client (`RemoteControl`) to switch the state of a `Light` object without directly coupling them. The `LightOnCommand` and `LightOffCommand` encapsulate the actions, while the `RemoteControl` acts as the invoker.

The Command Pattern is particularly useful in scenarios where you need to decouple objects that issue commands from objects that perform the actual actions. It's commonly used in GUI applications, where user actions are encapsulated as commands that can be executed, undone, and even stored for later use.
