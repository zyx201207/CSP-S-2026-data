#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a.begin()+1,a.end());

    auto check=[&](int len) -> bool
    {
        int need=0;
        for(int i=1;i<=len;++i) need+=a[len]-a[i];
        if(need<=m) return 1;
        for(int r=len+1;r<=n;++r)
        {
            need-=a[r-1]-a[r-len];
            need+=(a[r]-a[r-1])*(len-1);
            if(need<=m) return 1;
        }
        return 0;
    };

    int l=1,r=n;
    int res=0;
    while(l<=r)
    {
        int mid=l+(r-l>>1);
        if(check(mid))
        {
            res=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<res;

    return 0;
}