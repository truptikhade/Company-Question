#include <iostream>
#include <vector>
using namespace std;

struct Position
{
    int x;
    int y;
    int z;
};

enum Direction
{
    N,
    S,
    E,
    W,
    Up,
    Down
};
Direction rovdir = N;

void moveForward(Position &pos, Direction dir)
{
    switch (dir)
    {
    case N:
        pos.y++;
        break;
    case S:
        pos.y--;
        break;
    case E:
        pos.x++;
        break;
    case W:
        pos.x--;
        break;
    case Up:
        pos.z++;
        break;
    case Down:
        pos.z--;
        break;
    }
}

void moveBackward(Position &pos, Direction dir)
{
    switch (dir)
    {
    case N:
        pos.y--;
        break;
    case S:
        pos.y++;
        break;
    case E:
        pos.x--;
        break;
    case W:
        pos.x++;
        break;
    case Up:
        pos.z--;
        break;
    case Down:
        pos.z++;
        break;
    }
}

void turnLeft(Direction &dir)
{
    switch (dir)
    {
    case N:
        dir = W;
        rovdir = W;
        break;
    case S:
        dir = E;
        rovdir = E;
        break;
    case E:
        dir = N;
        rovdir = N;
        break;
    case W:
        dir = S;
        rovdir = S;
        break;
    case Up:
        dir = rovdir;
        turnLeft(dir);
        break;
    case Down:
        dir = rovdir;
        turnLeft(dir);
        break;
    }
}

void turnRight(Direction &dir)
{
    switch (dir)
    {
    case N:
        dir = E;
        rovdir = E;
        break;
    case S:
        dir = W;
        rovdir = W;
        break;
    case E:
        dir = S;
        rovdir = S;
        break;
    case W:
        dir = N;
        rovdir = N;
        break;
    case Up:
        dir = rovdir;
        turnRight(dir);
        break;
    case Down:
        dir = rovdir;
        turnRight(dir);
        break;
    }
}

void turnUp(Direction &dir)
{
    dir = Up;
}

void turnDown(Direction &dir)
{
    dir = Down;
}

int main()
{
    Position pos = {0, 0, 0};
    Direction dirr = N;

    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands)
    {
        switch (command)
        {
        case 'f':
            moveForward(pos, dirr);
            break;
        case 'b':
            moveBackward(pos, dirr);
            break;
        case 'l':
            turnLeft(dirr);
            break;
        case 'r':
            turnRight(dirr);
            break;
        case 'u':
            turnUp(dirr);
            break;
        case 'd':
            turnDown(dirr);
            break;
        }
    }

    cout << "Final Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << endl;
    cout << "Final Direction: ";
    switch (dirr)
    {
    case N:
        cout << "N";
        break;
    case S:
        cout << "S";
        break;
    case E:
        cout << "E";
        break;
    case W:
        cout << "W";
        break;
    case Up:
        cout << "Up";
        break;
    case Down:
        cout << "Down";
        break;
    }
    cout << endl;

    return 0;
}
