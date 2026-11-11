#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,x,y;
    cin>>a>>x>>b>>y;
    if(a==b)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(x[0]==y[0] && x[1]==y[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((x[2]=='A'&& y[2]=='B')||(x[2]=='A'&& y[2]=='C')||(x[2]=='B'&& y[2]=='C')||(x[2]=='B'&& y[2]=='A')||(x[2]=='C'&& y[2]=='A')||(x[2]=='C'&& y[2]=='B')||(x[2]=='D'&& y[2]=='F')||(x[2]=='F'&& y[2]=='D'))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(x[2]-y[2])==1)cout<<1;
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}
