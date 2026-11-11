#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;

ll A[N];
ll D[N],cnt[N],nmax[N];
ll ans=0;
ll n,m,mn=1e12;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    sort(A+1,A+n+1,less<ll>());
    for(ll i=2;i<=n;i++)D[i]=A[i]-A[i-1];
    ll flag=1;
    for(ll i=3;i<=n;i++)if(D[i]!=D[i-1])flag=0;
    if(flag)
    {//&&n>5000
        flag=D[2];
        ll ct=0,tot=1;
        while(ct+tot*flag<=m)ct+=(tot++)*flag;
        cout<<min(tot,n);

        return 0;
    }
    cnt[1]=0;
    for(ll i=2;i<=n;i++)
    {
        cnt[i]=cnt[i-1]+(i-1)*(A[i]-A[i-1]);
    }
    for(ll i=n;i>ans;i--)
    {
        ll ct=cnt[i];
        ll p=i;
        for(ll j=1;ct>m;j++)ct=ct-A[i]+A[j],p--;
        ans=max(ans,p);
    }
    cout<<ans;
    return 0;
}