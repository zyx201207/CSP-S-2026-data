#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    char b;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        if(a<=5){
            cout<<2;
            return 0;
        }
        if(a<=10){
            cout<<5;
            return 0;
        }
        if(a<=200){
            cout<<100;
            return 0;
        }
        if(a<=2000){
            cout<<1000;
            return 0;
        }
        if(a<=20000){
            cout<<10000;
            return 0;
        }
        if(a<=1000000000){
            cout<<3000000000;
            return 0;
        }
    }
    return 0;
}
