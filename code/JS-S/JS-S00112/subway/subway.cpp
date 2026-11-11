#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll num = 0,sign = 1;char ch = getchar();
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return (sign > 0 ? num : -num);
}
const int maxn = 2e4 + 8,maxsz = 2e4 + 500 + 8;
const ll inf = 1e18;
int c,n,m,q,d,wv[maxn],vis[maxsz];ll x,dis[510][maxsz],k[maxn],u1[510][maxn],w1[510][maxn];
vector<pair<int,ll> > adj[maxsz];
bool A = 1;
inline void add(int u,int v,ll w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
void dijsktra(int s){
    for(int i = 1;i <= n + m;i++) dis[s - m][i] = inf,vis[i] = 0;
    priority_queue<pair<int,ll> > pq;pq.push({0,s}),dis[s - m][s] = 0;
    while(!pq.empty()){
        auto[_,u] = pq.top();pq.pop();
        if(vis[u]) continue;vis[u] = 1;
        for(auto[v,w] : adj[u]){
            if(dis[s - m][u] + w < dis[s - m][v]){
                dis[s - m][v] = dis[s - m][u] + w;
                pq.push({-dis[s - m][v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read(),n = read(),m = read(),d = read(),q = read();
    for(int i = 1;i <= m;i++) wv[i] = read();
    for(int i = 1;i <= n;i++){
        k[i] = read();
        for(int j = 1;j <= k[i];j++){
            u1[i][j] = read(),w1[i][j] = read();
            if(i == 1 && j == 1) x = w1[i][j];
            A = (A && x == w1[i][j]);
        }
    }
    if(A){
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= k[i];j++)
                add(u1[i][j],m + 1,x);
        n = 1;
    }
    else{
         for(int i = 1;i <= n;i++)
            for(int j = 1;j <= k[i];j++)
                add(u1[i][j],m + i,w1[i][j]);
    }
    for(int i = 1;i <= n;i++) dijsktra(i + m);
    for(int i = 1;i <= q;i++){
        int s = read(),t = read();ll ans = inf;
        for(int j = 1;j <= n;j++) ans = min(ans,dis[j][s] + dis[j][t]);
        cout << ans + wv[s] + wv[t] << '\n';
    }
    return 0;
}
