#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,b1,b2;
    char c1,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    cout<<(a1==a2)<<(a1==a2 and b1==b2);
    cout<<(a1==a2 and b1==b2 and((c1<='C' and c2<='C')or(c1>='D' and c2>='D')));
    cout<<(a1==a2 and b1==b2 and((c1>='D' and c2>='D')or((c1<='C' and c2<='C')and(abs(c1-c2)==1))))<<"\n";
    return 0;
}
