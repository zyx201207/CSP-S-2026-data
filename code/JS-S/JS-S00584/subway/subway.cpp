#include<bits/stdc++.h>
using namespace std;
int use_less;
int n,m,d,q;
int nx,cnt=0;
int dis_station[20010];
int f[20010];
bool spA=1;
bool spB=1;
int sx,ex,dfs_fx;
long long ans=0;
int a[20010];
int dis_p[20010];
int sta_dis[510][20010];
vector<int> edge[20010];
struct road
{
    int u;
    int v;
    int p;
    int number;
}way[500010];
int ra=0;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>use_less>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%d",&dis_station[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&nx);
        for(int j=1;j<=nx;j++)
        {
            scanf("%d%d",&a[i],&dis_p[i]);
            sta_dis[i][a[i]]=dis_p[i];
        }
    }
    for(int i=1;i<=m;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(f[i]=i) dfs_fx=i;
        else edge[f[i]].push_back(i);
    }
    while(q--)
    {
        ans=0;
        scanf("%d%d",&sx,&ex);
        ans+=dis_station[sx]+dis_station[ex];
        long long cnt1=0;
        long long ans1=1e18;
        for(int i=1;i<=n;i++)
        {
            cnt1+=sta_dis[i][sx]+sta_dis[i][ex];
            ans1=min(ans1,cnt1);
        }
        ans+=ans1;
        cout<<ans<<endl;
    }
}
