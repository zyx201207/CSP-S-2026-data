#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 5e5 + 5;
int curtask;
int n,m,d,q;
int w[maxm];
vector<int> lin[maxm];
int t[505][maxm];
vector<pair<int,ll> > G[505];
void add(int u,int v,ll w)
{
    G[u].push_back({v,w});
}
struct node{
    int u;
    ll d;
    bool operator<(const node &oth)const
    {
        return d > oth.d;
    }
};
void dijkstra(ll dis[],int s)
{
    for(int i = 1;i <= n;i++) dis[i] = 1e18;
    dis[s] = 0;
    priority_queue<node> q;
    q.push({s,0});
    while(!q.empty())
    {
        int u = q.top().u;
        ll d = q.top().d;
        q.pop();
        if(d > dis[u]) continue;
        for(auto eedd : G[u])
        {
            int v = eedd.first;
            ll w = eedd.second;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                q.push({v,dis[v]});
            }
        }
    }
}
ll dis[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> curtask >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++) t[i][j] = -1;
        int k;
        cin >> k;
        while(k--)
        {
            int point;
            cin >> point;
            cin >> t[i][point];
            lin[point].push_back(i);
        }
    }
    for(int j = 1;j <= m;j++)
    {
        int sz = lin[j].size();
        for(int x = 0;x < sz;x++)
        {
            for(int y = x + 1;y < sz;y++)
            {
                add(lin[j][x],lin[j][y],1ll * (t[lin[j][x]][j] + t[lin[j][y]][j]));
                add(lin[j][y],lin[j][x],1ll * (t[lin[j][x]][j] + t[lin[j][y]][j]));
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        dijkstra(dis[i],i);
    }
    while(q--)
    {
        int st,en;
        cin >> st >> en;
        int szst = lin[st].size(),szen = lin[en].size();
        ll ans = 1e18;
        for(int x = 0;x < szst;x++)
        {
            for(int y = 0;y < szen;y++)
            {
                ans = min(ans,dis[lin[st][x]][lin[en][y]] + t[lin[st][x]][st] + t[lin[en][y]][en]);
                // if(lin[st][x] == 1 && lin[en][y] == 1)
                // {
                //     cout << "here:" << ans << ' ' << dis[lin[st][x]][lin[en][y]] + t[lin[st][x]][st] + t[lin[en][y]][en] << '\n';
                // }
            }
        }
        ans = ans + 1ll * w[st] + w[en];
        cout << ans << '\n';
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/



/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/