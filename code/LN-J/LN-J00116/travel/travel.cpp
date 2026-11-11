#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string a,b,c,d;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    int ax=(a[0]-'0')*10+(a[1]-'0');
    int bx=(b[0]-'0')*10+(b[1]-'0');
    int cx=(c[0]-'0')*10+(c[1]-'0');
    int dx=(d[0]-'0')*10+(d[1]-'0');
    if(ax==cx){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(bx==dx)
        cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(bx==dx){
        if(b[2]=='C'&&d[2]=='D'||(b[2]=='D'&&d[2]=='C')){
            cout<<"00";
            return 0;
        }
        else
            cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(dx==bx&&abs(b[2]-d[2])==1)
        cout<<1;
    else
        cout<<0;
    return 0;

}
