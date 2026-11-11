#include<bits/stdc++.h>
using namespace std;
long long e,t,n,m,a[10000],s[10000],Min=1000,ans=0;
void dfs(long long x,long long y,long long cnt)
{

    if(x>y)return;
    if(x==y)
    {
        Min=min(Min,cnt);
        s[cnt]++;
        return;
    }
    long long ss=0,ii=x,l=0;
    while(ss<=m)
    {
        ss+=a[ii+1]-a[ii];
        l++;
    }
    for(long long i=1;i<=l;i++)
    {
        dfs(x+i,y,cnt+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>e>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        for(long long i=0;i<n;i++)cin>>a[i];
        for(long long i=0;i<n;i++)
        {
            for(long long j=i+1;j<n;j++)
            {
                for(long long u=0;u<n;u++)
                {
                    s[u]=0;
                }
                Min=1000;
                if(m>a[j]-a[i])
                {
                    continue;
                }
                dfs(i,j,0);
                if(s[Min]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
