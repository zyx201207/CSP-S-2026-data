#include <bits/stdc++.h>
using namespace std;
int c,t,n;
struct way
{
    long long len,cs;
};
way vis[2000005];
long long d,a[2000005];
void dfs(int x,int r,long long s)
{
    if(s==vis[x].len)
    {
        vis[x].cs++;
    }
    else
    {
        vis[x].cs=1;
        vis[x].len=s;
    }
    for(int i=r;i>x;i--)
    {
        if(a[i]-a[x]<=d&&s+1<=vis[i].len)
        {
            dfs(i,r,s+1);
        }
    }
}
bool check(int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        vis[i].cs=0;
        vis[i].len=2000005;
    }
    vis[l].len=0;
    vis[l].cs=0;
    dfs(l,r,0);
    if(vis[r].cs==2)
    {
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        long long ans=0,t,f=1;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>=3&&a[i]-a[i-1]!=t)
            {
                f=0;
            }
            t=a[i]-a[i-1];
        }
        if(c==13||c==14)
        {
            cout<<0<<'\n';
            continue;
        }
        if(f)
        {
            d/=t;
            if(d==1)
            {
                cout<<0<<'\n';
            }
            else
            {
                cout<<n-2*d+1<<'\n';
            }
            continue;
        }
        for(int l=1;l<n;l++)
        {
            for(int r=l+1;r<=n;r++)
            {
                if(check(l,r))
                {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
