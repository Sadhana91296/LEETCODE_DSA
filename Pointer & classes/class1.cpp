#include<iostream>
using namespace std;
class cookies{
private:
 string color;
public:
   cookies(string color){
   this->color=color;
   }
   string getColor(){
   return color;
   }
   void setColor(string color)
   {
    this->color=color;
   }

};
int main()
{
    cookies* firstobj=new cookies("red");
    cookies* secondobj=new cookies("yellow");
    cout<<firstobj->getColor()<<endl;
    cout<<secondobj->getColor()<<endl;
    firstobj->setColor("green");
    cout<<firstobj->getColor()<<endl;

return 0;
}