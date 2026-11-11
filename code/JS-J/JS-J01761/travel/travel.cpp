#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1]) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(b[2]<='C'&&d[2]<='C'){
        cout<<1;
        if(int(b[2])+1==int(d[2])||int(b[2])-1==int(d[2])) cout<<1;
        else cout<<0;
        return 0;
    }
    else if(b[2]>='D'&&d[2]>='D') cout<<11;
    else{
        cout<<"00";
        return 0;
    }
    return 0;
}
