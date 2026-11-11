#ifndef TRAVEL_CPP_INCLUDED
#define TRAVEL_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if (c1==c3) cout<<1;
    else cout<<0;
    if (c2[0]==c4[0]&&c2[1]==c4[1]){
        cout<<1;
        if ((c2[2]=='F'||c2[2]=='D')&&(c4[2]=='F'||c4[2]=='D')){
            cout<<1;
            cout<<1;
        }else if ((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C')){
            cout<<1;
            if ((c2[2]=='A'&&c4[2]=='C')||(c4[2]=='A'&&c2[2]=='C')) cout<<0;
            else cout<<1;
        }else{
            cout<<0<<0;
        }
    }else{
        cout<<0<<0<<0;
    }
    return 0;
}
#endif // TRAVEL_CPP_INCLUDED
