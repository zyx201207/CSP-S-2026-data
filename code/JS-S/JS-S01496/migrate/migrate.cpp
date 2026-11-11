#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+2;
ll n,d,ans;
ll a[N];
ll nx[N];
ll in[N];
ll um[N];
void dfs(ll x,ll num)
{
    if(in[x]<num)return ;
    if(in[x]==num)
    {
        if(um[x]==2)ans--;
        um[x]++;
        if(um[x]==2)ans++;
    }
    else
    {
        in[x]=num;
        if(um[x]==2)ans--;
        um[x]=1;
    }
    for(int i=nx[x];i>x;i--)
    {
        dfs(i,num+1);
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,T;
    scanf("%lld%lld",&c,&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&d);
        ans=0;
        ll la=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            while(a[i]-a[la]>d)
            {
                nx[la++]=i-1;
            }
        }
        while(la<=n)
            nx[la++]=n;
        for(int i=1;i<=n;i++)
        {
            memset(um,0,sizeof(um));
            memset(in,0x3f,sizeof(in));
            dfs(i,0);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
