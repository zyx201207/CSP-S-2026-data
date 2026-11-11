#include<bits/stdc++.h>
using namespace std;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s,t;
    cin>>a>>s>>b>>t;
    if(a!=b){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s[1]!=t[1]||s[0]!=t[0]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    int d1=(s[2]<='C'&&s[2]>='A'),d2=(t[2]<='C'&&t[2]>='A');
    if(d1!=d2){
        cout<<"00";
        return 0;
    }
    cout<<1;
    int k=abs(s[2]-t[2]);
    if(k==1)cout<<1;
    else cout<<0;
    return 0;
}

