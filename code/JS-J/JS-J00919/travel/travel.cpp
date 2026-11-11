#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3;
string ax,ay,bx,by,a,b;
char aa,bb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ay>>ax>>by>>bx;
    if(by==ay){
        cout<<1;
        f1=1;
    }
    else cout<<0;
    a=ax[0]+ax[1];
    b=bx[0]+bx[1];
    if(a==b && f1){
        cout<<1;
        f2=1;
    }
    else cout<<0;
    aa=ax[2];
    bb=bx[2];
    char x=aa;
    char y=bb;
    if(f2){
        if(x=='A' || x=='B' || x=='C'){
            if(y=='A' || y=='B' || y=='C'){
                cout<<1;
                f3=1;
            }
            else cout<<0;
        }
        if(x=='E' || x=='F'){
            if(y=='E' || y=='F'){
                cout<<1;
                f3=1;
            }
            else cout<<0;
        }
    }
    else cout<<0;
    if(f3){
        if(x=='E' && y=='F') cout<<1;
        else if(x=='A' && y=='B') cout<<1;
        else if(x=='B' && y=='C') cout<<1;
        else if(x=='F' && y=='E') cout<<1;
        else if(x=='B' && y=='A') cout<<1;
        else if(x=='C' && y=='B') cout<<1;
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
