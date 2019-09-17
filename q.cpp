#include "Stack.h"

int main()
{
    Stack stack1;
    int array1[3] = {5, 6, 8};
    stack1.push(array1);
    int *pusharray;
    pusharray = stack1.pop();

    for ( int i = 0; i < 3; i++ ) {
      cout << (pusharray[i]) << endl;
   }
    return 0;
}