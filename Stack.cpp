//#include "Stack.h"
#include<iostream>
using namespace std;

class Stack
{
public:
    int top;
    int stackArray[][3];
public:
    int stacktop[];
    Stack()
    {

        top = -1;
        stackArray[100][3];
    }
    int * pop()
    {
        static int stacktop[3];
        if (top != -1)
        {
            for (int i = 0; i < 3; i++)
            {
                stacktop[i] = stackArray[top][i];
                
            }
            top--;
        }
        else
        {
            // print error
        }
        return stacktop;
    }

    void push(int *value)
    {
        if (top < 100)
        {
            top++;
            for (int i = 0; i < 3; i++)
            {
                stackArray[top][i] = value[i];
            }
        }
        else
        {
            //print error
        }
    }
};

// int main()
// {
//     Stack stack1;
//     int array1[3] = {5, 6, 8};
//     stack1.push(array1);
//     int *pusharray;
//     pusharray = stack1.pop();

//     for ( int i = 0; i < 3; i++ ) {
//       cout << (pusharray[i]) << endl;
//    }
//     return 0;
// }