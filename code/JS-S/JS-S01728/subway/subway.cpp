#include <bits/stdc++.h>
using namespace std;
long long n,m,c,d,q;
struct node{
    long long to,we;
};
vector<node>g[500005];
long long w[500002];
long long kk[500002][2];
long long dis[500002];
long long vis[500002];
void dd(long long st)
{
    for(int i=1;i<=m;i++)
    {
        dis[i]=0x3f3f3f3f;
        vis[i]=0;
    }
    dis[st]=0;
    int uu=st;
    for(int i=1;i<=m;i++)
    {
        vis[uu]++;
        for(int j=0;j<g[uu].size();j++)
        {
            long long too=g[uu][j].to;
            if(dis[too]>dis[uu]+g[uu][j].we)
            {
                dis[too]=dis[uu]+g[uu][j].we;
            }
        }
        long long minn=0x3f3f3f3f;
        for(int j=1;j<=m;j++)
        {
            if(vis[j]==0)
            {
                if(minn>dis[j])
                {
                    minn=dis[j];
                    uu=j;
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        long long t;
        scanf("%lld",&t);
        for(int j=1;j<=t;j++)
        {
            scanf("%lld%lld",&kk[j][0],&kk[j][1]);
            for(int k=1;k<j;k++)
            {
                node tt;
                tt.to=kk[j][0];
                tt.we=kk[j][1]+kk[k][1];
                g[kk[k][0]].push_back(tt);
                tt.to=kk[k][0];
                g[kk[j][0]].push_back(tt);
            }
        }
    }
    while(q--)
    {
        long long st,en;
        scanf("%lld%lld",&st,&en);
        dd(st);
        printf("%lld\n",dis[en]+w[st]+w[en]);
    }
    return 0;
}
