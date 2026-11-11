/*
CSP-S 2026 T1
Author:DFLJ

--I will win.

Passed at 14:45

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],s[500001];
bool chk(int d)
{
    bool f=0;
    for(int i=d; i<=n; i++)
    {
        int lft=i-d+1;
        int sum=s[i]-s[lft-1];
        int nd=a[i]*d;
        if(nd-sum<=m) f=1;
    }
    return f;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
    int l=0,r=1e6,mid,ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(chk(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}