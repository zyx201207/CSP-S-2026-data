#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1,b1;
char a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>a1>>a2>>m>>b1>>b2;
    if(n!=m)
        cout<<"0000";
    else{
        if(a1!=b1)
            cout<<"1000";
        else{
            if(a2=='A'&&b2=='B')
                cout<<"1111";
            else if(a2=='B'&&b2=='C')
                cout<<"1111";
            else if(a2=='C'&&b2=='B')
                cout<<"1111";
            else if(a2=='B'&&b2=='A')
                cout<<"1111";
            else if(a2=='D'&&b2=='F')
                cout<<"1111";
            else if(a2=='F'&&b2=='D')
                cout<<"1111";
            else if(a2=='A'&&b2=='C')
                cout<<"1110";
            else if(a2=='C'&&b2=='A')
                cout<<"1110";
            else
                cout<<"1100";
        }
    }
    return 0;
}
