#include <bits/stdc++.h>
using namespace std;
string xc,rc,xs,rs;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>xc>>xs>>rc>>rs;
    if(xc!=rc){
        cout<<"0000";
        return 0;
    }
    if(xs[0]+xs[1]!=rs[0]+rs[1]){
        cout<<"1000";
        return 0;
    }
    if(!((xs[2]>='A'&&xs[2]<='C'&&rs[2]>='A'&&rs[2]<='C')||(xs[2]>='D'&&xs[2]<='F'&&rs[2]>='D'&&rs[2]<='F'))){
        cout<<"1100";
        return 0;
    }
    if(!(xs[2]=='A'&&rs[2]=='B')||(xs[2]=='B'&&rs[2]=='C')||(xs[2]=='B'&&rs[2]=='A')||(xs[2]=='B'&&rs[2]=='C')||(xs[2]=='D'&&rs[2]=='F')||(xs[2]=='F'&&rs[2]=='D')){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
