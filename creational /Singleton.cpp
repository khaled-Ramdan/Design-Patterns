#include <bits/stdc++.h>
using namespace std;
class Logger
{
public:
    static Logger &getInstance()
    {
        static Logger *instance = new Logger;
        return *instance;
    }
    void printMessages()
    {
        cout << "Accessing Logger\n";
        for (auto e : messages)
            cout << e << endl;
    }
    void addMessage(string s)
    {
        messages.push_back(s);
    }

private:
    Logger()
    {
        cout << "Logger is created\n";
    }
    ~Logger()
    {
        cout << "Logger was deleted\n";
    }
    vector<string> messages;
};
int main()
{
    Logger::getInstance().addMessage("Hi");
    Logger::getInstance().printMessages();
}
