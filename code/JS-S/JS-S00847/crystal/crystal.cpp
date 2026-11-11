#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans,m,a[500001],pre[500001];
ll sum(int l,int r)
{
    return pre[r]-pre[l-1];
}
ll chk(int l,int r)
{
    ll res=a[r]*(r-l+1);
    res-=sum(l,r);
    return res;
}
ll calc(int l,int i)
{
    ll r=i,mid=(l+r)>>1,res=chk(mid,i);
    while(l<r||res>m)
    {
        mid=(l+r)>>1,res=chk(mid,i);
        if(res==m||l==r)
            return i-mid+1;
        else if(res>m)
            l=mid+1;
        else
            r=mid;
    }
    return i-mid+1;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans=max(calc(1,i),ans);
    cout<<ans<<endl;
    return 0;
}
