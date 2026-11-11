#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,n,m,d,q,w[N];
//c = 1 -> 6
//n <= 50
//m,ki <= 300
//q <= 200
int k[55];  //yi tiao xian de zhan shu liang
int a[55][305],t[55][305];  //dao da zhan he shi jian
int dis[305],vis[305];
struct st
{
    int v,w;
};
vector<st> g[305];
struct node
{
    int x,dis;
    bool operator<(const node &t)const
    {
        return dis>t.dis;
    }
};

//c = 7 -> 11
//n <= 500
//m,ki <= 1000
//q <= 100000
int k666[1005];  //yi tiao xian de zhan shu liang
int a666[1005][5],t666[1005][5];  //dao da zhan he shi jian
int g666[1005][1005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c<=6)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
            for(int j=1;j<=k[i];j++)
                for(int l=1;l<=k[i];l++)
                    g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
        }
        while(q--)
        {
            int sx,ex;
            cin>>sx>>ex;
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            priority_queue<node> que;
            que.push({sx,0});
            dis[sx]=0;
            while(!que.empty())
            {
                node hd=que.top();
                que.pop();
                int x=hd.x;
                if(vis[x]) continue;
                vis[x]=1;
                for(st i:g[x])
                {
                    int v=i.v,ww=i.w;
                    if(dis[x]+ww<dis[v])
                    {
                        dis[v]=dis[x]+ww;
                        que.push({v,dis[v]});
                    }
                }
            }
            cout<<dis[ex]+w[sx]+w[ex]<<'\n';
        }
        return 0;
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        cin>>k666[i];
        for(int j=1;j<=k666[i];j++) cin>>a666[i][j]>>t666[i][j];
        for(int j=1;j<=k666[i];j++)
            for(int l=1;l<=k666[i];l++)
                g666[a666[i][j]][a666[i][l]]=min(g666[a666[i][j]][a666[i][l]],t666[i][j]+t666[i][l]);
    }
    for(int l=1;l<=m;l++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                g666[i][j]=min(g666[i][j],g666[i][l]+g666[l][j]);
    while(q--)
    {
        int sx,ex;
        cin>>sx>>ex;
        cout<<g666[sx][ex]+w[sx]+w[ex]<<'\n';
    }
	return 0;
}
