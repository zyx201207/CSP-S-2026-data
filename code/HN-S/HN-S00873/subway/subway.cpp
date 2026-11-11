#include<bits/stdc++.h>
#define int long long
using namespace std;
int id,n,m,d,q;
int dis[505][505];
int w[500005];
struct node
{
    int id,x;
}op[500005][21];
int len[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>id>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a>>t,op[a][++len[a]]={i,t};
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=1e18;
            if(i==j) dis[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=len[i];j++)
        {
            for(int k=1;k<j;k++) dis[op[i][j].id][op[i][k].id]=dis[op[i][k].id][op[i][j].id]=min(dis[op[i][j].id][op[i][k].id],op[i][j].x+op[i][k].x);
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s,t;
        cin>>s>>t;
        int minn=1e18;
        for(int j=1;j<=len[s];j++)
        {
            for(int k=1;k<=len[t];k++) minn=min(minn,dis[op[s][j].id][op[t][k].id]+op[s][j].x+op[t][k].x+w[s]+w[t]);
        }
        cout<<minn<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/