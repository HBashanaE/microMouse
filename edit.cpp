#include<iostream>
using namespace std;
int main(){
    int a[][4] = {  
    {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
    {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
    {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
    };
    int inp[]={1,2,3};
    std::cout<< inp[2]<<' ';

    cout << "Hello, World!";
    cout << a[3][2];
    std::cout<< a[2][1]<<' ';
    return 0;
}


