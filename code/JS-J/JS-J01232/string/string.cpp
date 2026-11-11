#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=110,y=110,z=0,c;
    while(x!=0||y!=0){
        z+=((x%10)&&(y&10))*pow(10,cnt);
        x/=10;
        y/=10;
    }
    return 0;
}
