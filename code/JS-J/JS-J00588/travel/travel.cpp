#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    string x,y;
    x=x+b[0]+b[1];
    y=y+d[0]+d[1];
    if(x==y) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    int o=int(b[2])-64,p=int(d[2])-64;
    if(o<=3&&p<=3 || o>=4&&p>=4) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(o-p)==1) cout<<1;
    else cout<<0;
    return 0;



}
