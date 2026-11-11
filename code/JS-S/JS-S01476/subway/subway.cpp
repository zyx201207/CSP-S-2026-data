#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+8;
const int N = 5e2+8;
const int INF = 0x3f3f3f3f;

int c,n,m,d,q,w[M],dis[N],cnt[N],route[N][N];
vector<pair<int,int>> g[N][2];
//0:station to stage

void dijkstra(int s){
    priority_queue<tuple<int,int,bool>> pq;
    dis[s] = 0;pq.push({-dis[s],s,0});
    cnt[s] = 1;
    while(!pq.empty()){
        auto [_,u,lyr] = pq.top();
        //cout << lyr << "\n";
        pq.pop();
        if(cnt[u] > n) continue;
        for(auto [v,w]:g[u][lyr]){
            if(dis[v] > dis[u]+w){
                dis[v] = dis[u]+w;
                cnt[v] = cnt[u]+1;
                pq.push({-dis[v],v,!lyr});
            }
        }
    }
    for(int i = 1;i <= m;i++){
        route[s][i] = dis[i]+w[s]+w[i];
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    while(c--){
        for(int i = 1;i <= m;i++){
            cin >> w[i];
        }
        //the i railway
        for(int i = 1,k;i <= n;i++){
            cin >> k;
            for(int j = 1,a,t;j <= k;j++){
                cin >> a >> t;
                g[a][0].push_back({j,t});
                g[j][1].push_back({a,t});
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++){
            dis[j] = INF;
        }
        for(int j = 1;j <= m;j++){
            cnt[j] = 0;
        }
        dijkstra(i);
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= m;j++){
            cout << route[i][j] << " ";
        }
        cout << "\n";
    }
    //while(q--){
    //    int x,y;
    //    cin >> x >> y;
    //    cout << route[x][y] << "\n";
    //}

}
