#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],mid,ans,sum1,vis[200005],maxn;
bool check(ll n,ll m)
{
    while(n!=1)
    {
        if(n%2!=0)
        {
            return 0;
        }
        n/=2;
    }
    return 1;
}
void dfs(ll x,ll sum)
{
    if(x>m)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i <= n;i++)
    {
        if(vis[i]==0)
        {
            if(x==1)
            {
                vis[i]=1;
                dfs(x+1,a[i]);
                vis[i]=0;
            }else
            {
                vis[i]=1;
                dfs(x+1,sum&a[i]);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i  <= n; i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(i==1) sum1=a[i];
        else sum1&=a[i];
    }
    sort(a+1,a+1+n);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        cout<<sum1;
        return 0;
    }
    if(check(n,m)==1)
    {
        cout<<n-m;
    }
    if(m==2)
    {
        for(int i=1; i <= n; i++)
        {
            for(int j=1; j <= n; j++)
            {
                if(i==j) continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(maxn<=3)
    {
        cout<<
    }
    if(n<=20)
    {
        dfs(1,0);
        cout<<ans;
        return 0;
    }
}
