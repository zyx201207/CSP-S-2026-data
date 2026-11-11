#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int max(int a,int b){
    return (a>b ? a : b);
}
int min(int a,int b){
    return (a>b ? b : a);
}
bool cmp(int a,int b){
    return a<b;
}
ll n,m;
ll a[500005];
ll tot=-INF;
bool check(ll mid)
{
    ll cnt=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]>mid)
            break;
        else
            cnt+=mid-a[i];
        if(cnt>m)
            return false;
    }
    return true;
}
ll add(ll x)
{
    ll sum=0;ll t=m;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x)
            break;
        if(t>=x-a[i])
        {
            sum++;
            t-=x-a[i];
        }

    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll l=0,r=INF;
    ll mid;
    sort(a+1,a+n+1,cmp);
    while(l<r)
    {
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            tot=max(tot,add(mid));
        }
        else
            r=mid;
    }
    for(int i=1;i<=n;i++)
        if(a[i]==mid)tot++;
    cout<<tot;
    return 0;
}
