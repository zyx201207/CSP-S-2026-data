#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int a,b;
    string s,t;
    cin>>a>>s>>b>>t;
    bool x=false,y=false,z=false;
    if(a==b){
        x=true;
        cout<<1;
    }
    else cout<<0;
    int c=(s[0]-'0')*10+(s[1]-'0'),d=(t[0]-'0')*10+(t[1]-'0');
    if(x && c==d){
        y=true;
        cout<<1;
    }
    else cout<<0;
    c=s[2]-'A'+1,d=t[2]-'A'+1;
    if(y && ((c<=3 && d<=3) || (c>3 && d>3))){
        z=true;
        cout<<1;
    }
    else cout<<0;
    if(z && (c==d+1 || c==d-1)){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
