#include<bits/stdc++.h>
#define int long long
using namespace std;
void init(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
}
int c1,c2;
string s1,s2;
signed main(){
    init();
    cin>>c1>>s1>>c2>>s2;
    bool a,b,c,d;
    a=(c1==c2);
    b=(a and (s1.substr(0,2)==s2.substr(0,2)));
    c=(b and ((s1[2]<='C' and s2[2]<='C') or (s1[2]>='D' and s2[2]>='D')));
    d=(c and (abs(s1[2]-s2[2])==1));
    cout<<a<<b<<c<<d;
    return 0;
}
