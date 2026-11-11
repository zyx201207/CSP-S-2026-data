#include<bits/stdc++.h>
using namespace std;
#define int1 long long
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int1 n,m; cin>>n>>m;
    multiset<int1> S1;
    multiset<int1> S2;
    for(int i=0;i<n;i++)
    {
        int1 x; cin>>x;
        S1.insert(x);
    }
    int1 x=0;
    int1 t=0;
    for(auto c:S1)
    {
        if(t==n/2)
            x=c;
        t++;
    }
    for(auto c:S1)
        S2.insert(abs(c-x));
    int1 cnt=0;
    int1 t1=0;
    for(auto c:S2)
    {
        cnt+=c;
        if(cnt>m)
        {
            cout<<t1;
            return 0;
        }
        t1++;
    }
    return 0;
}
