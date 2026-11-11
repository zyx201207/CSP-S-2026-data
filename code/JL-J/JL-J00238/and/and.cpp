#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=pow(2,30)-1;
int n;
ll maxn;
int m;
ll a[200010];
bool vis[200010];
void dfs(int cishu,ll shu)
{
    if(cishu==0)
    {
        maxn=max(shu,maxn);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            dfs(cishu-1,shu&a[i]);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    ll m1=INT_MIN;
    ll m2=mod;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m1=max(m1,a[i]);
        m2=m2&a[i];
    }
    if(n<=20)
    {
        dfs(m,mod);
        cout<<maxn;
        return 0;
    }
    if(m==1)
    {
        cout<<m1;
        return 0;
    }
    if(m==n)
    {
        cout<<m2;
        return 0;
    }
    ll m3=INT_MIN;
    if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                m3=max(m3,a[i]&a[j]);
            }
        }
        cout<<m3;
        return 0;
    }
    int k=1,qw=2;
    bool m4=false;
    while(qw<=n)
    {
        qw*=2;
        k++;
        if(qw==n)
        {
            m4=true;
            break;
        }
    }
    sort(a+1,a+1+n);
    if(m4)
    {
        ll qw=a[n];
        for(int i=n-1;i>=n-m+1;i--)
        {
            qw=qw&a[i];
        }
        cout<<qw;
        return 0;
    }
    else
    {
        cout<<a[n-m+1];
        return 0;
    }
    return 0;
}
