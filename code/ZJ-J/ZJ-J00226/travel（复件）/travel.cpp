#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    char w1=s1[2];
    char w2=s2[2];
    if(w1>w2) swap(w1,w2);

    bool f1=(c1==c2);
    bool f2=(p1==p2);
    bool f3=(w2<='C'||w1>='D');
    bool f4=(w2==w1+1);

    cout<<f1<<(f1&&f2)<<(f1&&f2&&f3)<<(f1&&f2&&f3&&f4);

    return 0;
}