#include <bits/stdc++.h>
using namespace std;
class IGameObject
{
public:
    virtual ~IGameObject() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};
class Plane : public IGameObject
{
public:
    Plane() {}
    void Update() {}
    void Render() {}
};
class Boat : public IGameObject
{
    Boat() {}
    void Update() {}
    void Render() {}
};
enum class ObjectType
{
    PLANE,
    BOAT
};
shared_ptr<IGameObject> MakeGameObjectFactory(ObjectType type)
{
    if (type == ObjectType::PLANE)
        return make_shared<Plane>();
    else if (type == ObjectType::BOAT)
        return make_shared<Boat>();
    else
        return nullptr;
}
int main()
{
    shared_ptr<IGameObject> obj1 = MakeGameObjectFactory(ObjectType::PLANE);
    shared_ptr<IGameObject> obj2 = MakeGameObjectFactory(ObjectType::BOAT);
}
