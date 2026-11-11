#include <iostream>
#include <vector>
#include <queue>

using ll = long long;
const ll MAXN = 510, MAXM = 5e5+10;
const ll MAXVERS = 1520;
ll w[MAXN], dis[MAXVERS][MAXVERS];

ll test_id, n, m, d, plans;

ll head[MAXN+MAXM], nxt[MAXM], vxt[MAXM], wxt[MAXM];
void create_edge(ll u, ll v, ll w){
    static ll edgeID = 0;
    nxt[edgeID] = head[u];
    vxt[edgeID] = v;
    wxt[edgeID] = w;
    head[u] = edgeID++;
}

//记得清空！！！
ll cur_dis[MAXN];
bool vis[MAXN];

std::priority_queue<std::pair<ll,ll>,
    std::vector<std::pair<ll,ll>>> pq;
ll station_dis[MAXN][MAXN];
std::vector<std::pair<ll,ll>> vec[MAXN];

ll lineID(ll line){
    return line;}
ll subwayID(ll platform){
    return platform + 501;
}

void floyd_for_small()
{
    const ll node_max = subwayID(m);

    for(ll u = 1;u<=node_max;u++)
        for(ll v = 1;v<=node_max;v++)
            dis[u][v] = LLONG_MAX/2;
    
    for(ll i = 1;i<=node_max;i++)
        dis[i][i] = 0;

    for(ll i = 1;i<=n;i++){
        ll num;std::cin>>num;
        for(ll j = 1;j<=num;j++){
            ll k,w;std::cin >> k >> w;
            dis[lineID(i)][subwayID(k)] = w;
            dis[subwayID(k)][lineID(i)] = w;
        }
    }

    //Floyd
    for(ll k = 1;k<=node_max;k++){
        for(ll i = 1;i<=node_max;i++){
            for(ll j = 1;j<=node_max;j++){
                dis[i][j] = std::min(dis[i][k]+dis[k][j], dis[i][j]);
            }
        }
    }

    for(ll i = 1;i<=plans;i++){
        ll u, v;
        std::cin >> u >> v;
        std::cout << dis[subwayID(u)][subwayID(v)] 
                        + w[u] + w[v] << "\n";
    }
}

ll diji(ll u, ll v)
{
    if(station_dis[u][v])
        return station_dis[u][v];
    long long& ans = station_dis[u][v];
    for(ll i = 0;i<=n;i++)
        cur_dis[i] = LLONG_MAX/2;
    
    
    pq.push(std::make_pair(u,cur_dis[u]=0));
    while(!pq.empty())
    {
        ll cur = pq.top().first;
        if(vis[cur])    continue;
        vis[cur] = true;
        for(ll e=head[cur];e;e=nxt[e]){
            
        }
    }
}

void clever_sol()
{
    for(ll i = 1;i<=n;i++){
        ll num;std::cin>>num;
        for(ll j = 1;j<=num;j++){
            ll k,w;std::cin >> k >> w;
            create_edge(subwayID(k),lineID(i),w);
            create_edge(lineID(i),subwayID(k),w);
            vec[k].push_back(std::make_pair(i,w));
        }
    }

    for(ll u = 1;u<=n;u++){
        for(ll v = 1;v<=n;v++){
            station_dis[u][v] = diji(u,v);
            station_dis[v][u] = station_dis[u][v];
        }    
    }

    for(ll i = 1;i<=plans;i++)
    {
        ll ans = INT_MAX;
        ll u,v;std::cin>>u>>v;
        for(auto& x:vec[u])
            for(auto& y:vec[v])
                ans = std::min(ans,diji(x.first,y.first)
                    +w[u]+w[v]+x.second+y.second);
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::cin >> test_id >> n >> m >> d >> plans;

    for(ll i = 1;i<=m;i++)
        std::cin >> w[i];
    

    if(test_id <= 11)   floyd_for_small();
    else    clever_sol();

    return 0;
}