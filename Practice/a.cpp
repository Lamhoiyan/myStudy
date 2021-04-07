#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <cctype>

#include <iomanip>
using namespace std;

int pri(char ch){
    if(ch == '#') return 0;
    else if(ch == '$') return 1;
    else if (ch== '+' || ch=='-') return 2;
    else return 3;
}

double cal(double x,double y,char z){
    double result = 0;
    if(z=='+') result = x+y;
    else if(z=='-') result = x-y;
    else if(z=='*') result = x*y;
    else if(z=='/') result = x/y;
    return result;
}

double GetNumber(string str,int& index){//int& 为引用型，可以改变传递过来的参数本身的值，它们指向同一地址
    double number = 0;
    while(isdigit(str[index])){
        number = number*10 + str[index]-'0';//注意char转为int
        index++;
    }
    return number;
}

int main(){
    string a;
    
    while(getline(cin,a)){
        if(a =="0" )break;
        a+='$';
        int index =0;
        
        stack<double> num;
        stack<char> sym;
        sym.push('#');
        
        while(index<a.size()){
            
            if(a[index] ==' ') {
                index++;
            } 
            else if(isdigit(a[index])){
                num.push(GetNumber(a,index));
            }
            else{
                char ch = sym.top();
                if(pri(ch) < pri(a[index])){
                    sym.push(a[index]);
                    index++;
                }
                else{
                    double a1 = num.top();
                    num.pop();
                    double a2 = num.top();
                    num.pop();
                    num.push(cal(a1,a2,sym.top()));
                    sym.pop();
                }
            }
        }
        
        printf("%.2f\n",num.top());
    }
    return 0;
}