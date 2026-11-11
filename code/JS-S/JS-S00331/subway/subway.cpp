#include <bits/stdc++.h>
using namespace std;

const int Max = 5e5+505;

int c,n,m,d,q;
int w[Max];
vector <pair<int,int>> G[Max];
vector <long long> dist[505];
vector <bool> gt[505];
priority_queue <pair<long long,int>> pq;
void input(){
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1; i <= m; i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d",&k);
        for(int j = 1; j <= k; j++){
            int v,len;
            scanf("%d%d",&v,&len);
            G[i+m].push_back({v,len});
            G[v].push_back({i+m,len});
        }
    }
}
void get_dist(int x){
    for(int i = 1; i <= n+m; i++){
        dist[x][i] = 1e18;
    }
    dist[x][x+m] = 0;
    pq.push({0,x+m});
    while(!pq.empty()){
        auto temp = pq.top(); pq.pop();
        long long dis = temp.first; int cur = temp.second;
        if(gt[x][cur]) continue;
        gt[x][cur] = 1;
        for(auto edge : G[cur]){
            int nxt = edge.first, len = edge.second;
            if(dist[x][nxt] > -dis+len){
                dist[x][nxt] = -dis+len;
                pq.push({dis-len,nxt});
            }
        }
    }
}
void solve(){
    for(int i = 1; i <= n; i++){
        dist[i].resize(n+m+5);
        gt[i].resize(n+m+5);
        get_dist(i);
    }
}
void answer(){
    for(int i = 1; i <= q; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans = 2e18;
        for(int j = 1; j <= n; j++){
            ans = min(ans,dist[j][x]+dist[j][y]);
        }
        ans += w[x]+w[y];
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    input();
    solve();
    answer();
    return 0;
}
