#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char a1,a2;
int f1,f2;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>f1>>a1>>c2>>f2>>a2;
    if(c1==c2){
        a=1;
    }
    if(a==1){
        if(f1==f2){
            b=1;
        }
    }
    if(b==1){
        if((a1=='F'&&a2=='D')||(a1=='D'&&a2=='F')){
            c=1;
            d=1;
        }
        if((a1=='A'&&a2=='B')||(a1=='A'&&a2=='C')){
            c=1;
        }
        if((a1=='B'&&a2=='A')||(a1=='B'&&a2=='C')){
            c=1;
        }
        if((a1=='C'&&a2=='B')||(a1=='C'&&a2=='A')){
            c=1;
        }
        if(c==1){
            if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='A')||(a1=='B'&&a2=='C')||(a1=='C'&&a2=='B')){
                d=1;
            }
        }
    }
    cout<<a<<b<<c<<d;
    return 0;
}
