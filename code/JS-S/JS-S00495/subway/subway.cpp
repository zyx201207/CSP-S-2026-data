#include<bits/stdc++.h>
#define dg(x) #x<<':'<<(x)<<' '
#define int long long
using namespace std;

const int N=5e2+5,M=5e5+5,inf=1e15;

int c,n,m,d,q;
struct node{int v,w;};
vector<node> G[N],lnk[M];
void add(int u,int v,int w)
{G[u].push_back({v,w});}
int useless[M];
int dis[N][N],vis[N][N];

bool operator<(const node &x,const node &y)
{return x.w>y.w;}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>useless[i];
    for(int i=1,k,p,w;i<=n;i++)
    {
        cin>>k;
        // cout<<dg(i)<<dg(k)<<'\n';
        for(int j=1;j<=k;j++)
        {
            cin>>p>>w;
            // cout<<dg(p)<<dg(w)<<'\n';
            lnk[p].push_back(node{i,w});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto t1:lnk[i])
        {
            int p1=t1.v,w1=t1.w;
            for(auto t2:lnk[i])
            {
                int p2=t2.v,w2=t2.w;
                if(p1==p2) continue;
                add(p1,p2,w1+w2);
            }
        }
    }

    for(int s=1;s<=n;s++)
    {
        priority_queue<node> pq;
        for(int i=1;i<=n;i++)
            dis[s][i]=inf;
        dis[s][s]=0,pq.push({s,0});
        while(pq.size())
        {
            int u=pq.top().v;pq.pop();
            if(vis[s][u]) continue;
            vis[s][u]=1;
            for(auto tmp:G[u])
            {
                int v=tmp.v,w=tmp.w;
                if(dis[s][v]>dis[s][u]+w)
                    dis[s][v]=dis[s][u]+w,pq.push({v,dis[s][v]});
            }
        }
    }
    
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         cout<<dis[i][j]<<" \n"[j==n];

    while(q--)
    {
        int x,y;cin>>x>>y;
        int res=inf;
        for(auto t1:lnk[x])
        {
            int p1=t1.v,w1=t1.w;
            for(auto t2:lnk[y])
            {
                int p2=t2.v,w2=t2.w;
                // cout<<p1<<' '<<w1<<' '<<p2<<' '<<w2<<' '<<dis[p1][p2]<<'\n';
                res=min(res,dis[p1][p2]+w1+w2);
            }
        }
        cout<<res+useless[x]+useless[y]<<'\n';
    }

    return 0;
}
//@markding shenbenbaoyou