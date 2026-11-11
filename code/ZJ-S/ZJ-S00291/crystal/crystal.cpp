#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> sum(n);
    sum[0]=a[0];
    for(int i=1;i<n;++i) sum[i]=sum[i-1]+a[i];
    auto check=[&](int x)->bool
    {
        for(int l=0,r=l+x-1;r<n;++l,++r)
        {
            __int128 tot=a[r]*x;
            __int128 res=0;
            if(l==0) res=sum[r];
            else res=sum[r]-sum[l-1];
            if(tot-res<=m) return true;
        }
        return false;
    };
    int l=1,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1; 
    }
    cout<<ans;
}