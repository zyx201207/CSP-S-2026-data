#include <iostream>
using namespace std; 
long long a10t2(int ro);
int main()
{
    
    return 0;
}
long long a10t2(int ro){
    long long num=0;
    while(true){
        int tm=ro%2;
        num=(num*10)+tm;
        ro/=2;
        if(ro==0) break;
    }
    return num;
}