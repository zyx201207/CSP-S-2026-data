#include"bits/stdc++.h"
using namespace std;

bool li(char i,char j){
    if(i < j) swap(i,j);
    if (i=='C') return 0;
    else if(i-j ==1) return 1;
    return 0;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
            cout<<1;
    if(a2[0]==b2[0]&&a2[1]==b2[1])
    {
        cout<<1;
        bool ai,bi;
        if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C') ai=0;
        else ai=1;
        if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C') bi=0;
        else bi=1;

        if(ai==bi){
            cout<<1;
            cout<<li(a2[2],b2[2]);
        }
        else cout<<0<<0;
    }
    else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
}
