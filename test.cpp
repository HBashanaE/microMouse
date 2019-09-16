// CPP program to demonstrate working of STL stack
#include<iostream>
using namespace std; 
class Stack
{  
   public:
   static int stack[1000][3];
   int n;
   int top;
   Stack()
   {
      n=1000;
      top=-1;
   }
   void push(int val[3])
   {
      if(top>=n-1)
         cout<<"Stack Overflow"<<endl; 
      else {
         top++;
         stack[top][0]=val[0];
         stack[top][1]=val[1];
         stack[top][2]=val[2];
      }
   }
   void pop() {
      if(top<=-1)
         cout<<"Stack Underflow"<<endl;
      else {
         cout<<"The popped element is "<< stack[top] <<endl;
         top--;
      }
   }
   int topx(){
      return stack[top][0];
   }
   int topy(){
      return stack[top][1];
   }
   int topval(){
      return stack[top][2];
   }
   void display() {
      if(top>=0) {
         cout<<"Stack elements are:";
         for(int i=top; i>=0; i--)
            cout<<stack[i]<<" ";
            cout<<endl;
      } else{
         cout<<"Stack is empty";
      }
   }
};

int main() {
   Stack stack;
   int* a;
   a=5;
   stack.push(a);
   
/*   
   int ch;
   int val[3]; 
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val[3];
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4); 

   */

   return 0;
}