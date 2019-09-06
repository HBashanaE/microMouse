#include<iostream>
#include <stack>
using namespace std; 
int* floodFill(int world[][6], int hWall[][6], int vWall[][6])
{
    int x = 2;
    int y = 2;

    int worldWidth = sizeof(world);
    int worldHeight = sizeof(world[0]);
    stack<int[3]> theStack;
    theStack.push({x + 1, y + 1, 0});
    theStack.push({x + 1, y, 0});
    theStack.push({x, y+1, 0});
    theStack.push({x , y , 0});
    theStack.pop();
    while ((theStack.size()) > 0)
    {
        int stackData[3];
        int a,b,c;
        theStack.pop();
        int* stackData= theStack.top();
        return stackData;
        // print(theStack)

        // print(val)
        if (world[y][x] < val):
            // print('continued')
            continue

        world[y][x] = val

        if vWall[y][x] != 1:  // left
            // print('left')
            theStack.append((x - 1, y, val + 1))

        if hWall[y][x] != 1:  // up
            theStack.append((x, y - 1, val + 1))
            // print('up')

        if vWall[y][x + 1] != 1:  // right
            theStack.append((x + 1, y, val + 1))
            // print('right')

        if hWall[y + 1][x] != 1:  // down
            theStack.append((x, y + 1, val + 1))
            // print('down') 


            
    }
}

int main()
{
    int x = 2;
    int y = 2;

    //int worldWidth = sizeof(world);
    //int worldHeight = sizeof(world[0]);
    stack<int> theStack;
    theStack.push(1);
    theStack.push(5);
    // theStack.push({1, y + 1, 0});
    // theStack.push({x + 1, y, 0});
    // theStack.push({x, y+1, 0});
    // theStack.push({x , y , 0});
    cout<<theStack.top();
    theStack.pop();
    cout<<theStack.top();
        //int* stackData= theStack.top();
        //cout<<stackData[0];
    return 0;
}