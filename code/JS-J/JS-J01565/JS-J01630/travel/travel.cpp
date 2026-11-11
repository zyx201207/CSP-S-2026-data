#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    string r1,r2,x1,x2,t;
    cin>>r1>>r2>>x1>>x2;
    if(x2<r2){
        t=r2;
        r2=x2;
        x2=t;
    }
    if(r1==x1) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(r2[0]==x2[0]&&r2[1]==x2[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((r2[r2.size()-1]=='A'&&x2[x2.size()-1]=='B')||(r2[r2.size()-1]=='B'&&x2[x2.size()-1]=='C')||(r2[r2.size()-1]=='A'&&x2[x2.size()-1]=='C')||(r2[r2.size()-1]=='D'&&x2[x2.size()-1]=='F')) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if((r2[r2.size()-1]=='A'&&x2[x2.size()-1]=='B')||(r2[r2.size()-1]=='B'&&x2[x2.size()-1]=='C')||(r2[r2.size()-1]=='D'&&x2[x2.size()-1]=='F')) cout<<"1";
    else cout<<"0";
    freopen("travel.out","w",stdout);
    return 0;
}
