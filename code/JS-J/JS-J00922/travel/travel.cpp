#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string x=b.substr(0,2),y=d.substr(0,2);
    int s=b[2]-'A'+1,t=d[2]-'A'+1;
    if(s==6)s--;
    if(t==6)t--;
    if(a!=c)cout<<"0000";
    else if(x!=y)cout<<"1000";
    else if((s+t)>5&&(s+t)<9)cout<<"1100";
    else if(abs(s-t)!=1)cout<<"1110";
    else cout<<"1111";
    return 0;
}
