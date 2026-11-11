#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
// use ll!!! qingkong!!!
const int N = 510,M = 5e5+10;
int c,n,m,d,q;// n!=point!!! m = point!!!!
int wio[M];
int dis[N][N],vis[N][N],wmn[N][N];

int read()
{
    char c;
    int res = 0;
    while(c = getchar())
    {
        if(c >= '0'&& c <= '9')
        {
            res += c-'0';
            break;
        }
    }
    while(c = getchar())
    {
        if(c >= '0'&& c <= '9')
        {
            res *= 10;
            res += c-'0';
        }
        else
            break;
    }
    return res;
}

struct p{
    int hc[N];
    vector<int> way;
}st[M];

struct node{
    int u,dis;
    bool operator > (const node &rhs)const{
        return dis > rhs.dis;
    }
};

struct edge
{
    int v,w;
};
vector<edge> g[N];

void dijk(int s)
{
    priority_queue<node,vector<node>,greater<node> > q;
    dis[s][s] = 0;
    vis[s][s] = 1;
    q.push({s,0});
    while(!q.empty())
    {
        int u = q.top().u;
        q.pop();
        vis[s][u] = 1;
        for(auto [v,w]:g[u])
        {
            if(dis[s][v] > dis[s][u]+w)
            {
                dis[s][v] = dis[s][u]+w;
                if(vis[s][v] == 0)
                {
                    vis[s][v] = 1;
                    q.push({v,dis[s][v]});
                }
            }
        }
    }
}


signed main()
{
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> wio[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int x;
        cin >> x;
        for(int j = 1 ; j <= x ; j++)
        {
            int sta,cost;
            cin >> sta >> cost;
            //sta = read();
            //cost = read();
            st[sta].way.push_back(i);
            st[sta].hc[i] = cost;
        }
    }
    memset(wmn,0x3f,sizeof wmn);
    for(int i = 1 ; i <= m ; i++)
    {
        int cnt = st[i].way.size();
        if(cnt == 0||cnt == 1) continue;
        for(int w1:st[i].way)
        {
            for(int w2:st[i].way)
            {
                if(w1 == w2) continue;
                int cost = st[i].hc[w1]+st[i].hc[w2];//jianzhi
                if(cost >= wmn[w1][w2]) continue;
                wmn[w1][w2] = wmn[w2][w1] = cost;
                //g[w1].push_back({w2,cost});
                //g[w2].push_back({w1,cost});
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ;j <= n ; j++)
        {
            if(i == j) continue;
            if(wmn[i][j] != 0x3f3f3f3f3f3f3f3f)
            {
                g[i].push_back({j,wmn[i][j]});
                g[j].push_back({i,wmn[j][i]});
            }
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i = 1 ; i <= n ; i++)
    {
        dijk(i);
    }
    while(q--)
    {
        int qd,zd;
        cin >> qd >> zd;
        int qdhc = st[qd].way.size(),zdhc = st[zd].way.size();
        int ans = 1e18;
        for(int w1:st[qd].way)
        {
            for(int w2:st[zd].way)
            {
                int cost = dis[w1][w2]+wio[qd]+wio[zd]+st[qd].hc[w1]+st[zd].hc[w2];
                ans = min(ans,cost);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
