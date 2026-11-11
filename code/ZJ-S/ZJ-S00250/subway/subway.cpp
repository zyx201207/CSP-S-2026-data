#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int INF=1e18;
constexpr int maxn=2e6+10;
int c,n,m,d,q;
struct node
{
    int v,w;
    node()=default;
    node(int a,int b):v(a),w(b){}

    bool operator<(const node&o) const
    {
        return w>o.w;
    }
};
vector<node> gra[maxn];

bitset<maxn> vis;
int dis[maxn];
void dij(int s)
{
    for(int i=1;i<=2*m+n+10;++i)
    {
        vis[i]=0;
        dis[i]=INF;
    }
    dis[s]=0;

    priority_queue<node> q;
    q.emplace(s,0);
    while(!q.empty())
    {
        int u=q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:gra[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(v,dis[v]);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+1);
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }

    vector<vector<pair<int,int>>> way(m+1);
    for(int i=1,k;i<=n;++i)
    {
        cin>>k;
        for(int j=1,a,t;j<=k;++j)
        {
            cin>>a>>t;
            gra[m+i].emplace_back(a,t);
            gra[a].emplace_back(m+i,t);
            way[a].emplace_back(i,t);
        }
    }

    vector<vector<int>> disn(n+1,vector<int>(n+1));
    for(int i=1;i<=n;++i)
    {
        dij(m+i);
        for(int j=i+1;j<=n;++j)
        {
            disn[i][j]=disn[j][i]=dis[m+j];
        }
    }

    while(q--)
    {
        int s,t;
        cin>>s>>t;
        int res=w[s]+w[t];
        int mnw=INF;
        for(auto [i,ti]:way[s])
        {
            for(auto [j,tj]:way[t])
            {
                mnw=min(mnw,disn[i][j]+ti+tj);
            }
        }
        res+=mnw;
        cout<<res<<'\n';
    }

    return 0;
}