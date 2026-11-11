#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<char> c(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
    }

    int l=1,r=n;
    int ll=a[1],rr=a[n];
    int res=0;
    while(l<=r)
    {
        int mn=min(ll,rr);
        if(c[l]!=c[r]) res+=mn;
        ll-=mn,rr-=mn;
        if(!ll) ++l,ll=a[l];
        if(!rr) --r,rr=a[r];

    }
    cout<<res;


    return 0;
}