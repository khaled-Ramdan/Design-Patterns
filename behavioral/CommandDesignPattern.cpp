#include <bits/stdc++.h>
using namespace std;
struct Character
{
    int x;
    int y;
    string name;
    Character(string _name) : name(_name) {}
    void move(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
class Command
{
public:
    virtual ~Command() {}
    virtual void execute(Character &c) = 0;
    virtual void undo(Character &c) = 0;
};

class Move : public Command
{

public:
    void execute(Character &c)
    {
        x = rand() % 4;
        y = rand() % 4;
        c.move(x, y);
        cout << c.name << " moved " << x << " " << y << "\n";
    }
    void undo(Character &c)
    {
        c.move(-x, -y);
        cout << c.name << " undo " << -x << " " << -y << "\n";
    }

private:
    int x, y;
};

int main()
{
    srand(time(NULL));
    Character khaled("khaled");
    vector<Command *> commmand_queue;

    for (int i = 0; i < 4; i++)
    {
        Move *m = new Move;
        commmand_queue.push_back(m);
    }

    for (int i = 0; i < commmand_queue.size(); i++)
        commmand_queue[i]->execute(khaled);

    for (int i = commmand_queue.size() - 1; i >= 0; i--)
        commmand_queue[i]->undo(khaled);
}
