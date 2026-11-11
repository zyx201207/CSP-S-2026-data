#include<bits/stdc++.h>
using namespace std;

string r;
char r1;
char r2;
char r3;

string x;
char x1;
char x2;
char x3;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>r1>>r2>>r3>>x>>x1>>x2>>x3;
    if(r==x){
        cout<<'1';
        if(r1==x1 && r2==x2){
            cout<<'1';
            if(((r3<='C'&&r3>='A')&&(x3<='C'&&x3>='A'))
               ||((r3<='F'&&r3>='D')&&(x3<='F'&&x3>='D'))){
                cout<<'1';
                if((r3=='A'&&x3=='B')||(r3=='B'&&x3=='C')||(r3=='D'&&x3=='F')
                   ||(x3=='A'&&r3=='B')||(x3=='B'&&r3=='C')||(x3=='D'&&r3=='F')){
                    cout<<'1';
                }
                else {
                    cout<<'0';
                }
               }
               else {
                cout<<'0'<<'0';
               }
        }
        else {
            cout<<'0'<<'0'<<'0';
        }
    }
    else {
        cout<<'0'<<'0'<<'0'<<'0'<<'0';
    }

    return 0;
}
