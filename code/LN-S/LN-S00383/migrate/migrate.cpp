#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int _c,_t;
    cin>>_c>>_t;
    while(_t--){
        int n;
        ll d;
        cin>>n>>d;
        vector<ll> x(n + 1);
        for(int i = 1;i <= n;i++){
            cin>>x[i];
        }
        vector<vector<int>> G(n + 1);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < i;j++){
                if(max(x[i] - x[j],x[j] - x[i]) <= d){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int u = 1;u <= n;u++){
            vector<int> dis(n + 1,INT_MAX / 2);
            vector<int> cnt(n + 1);
            queue<int> q;
            q.push(u);
            dis[u] = 0;
            cnt[u] = 1;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto v : G[cur]){
                    if(dis[v] == dis[cur] + 1){
                        cnt[v] += cnt[cur];
                    }
                    else if(dis[v] > dis[cur] + 1){
                        cnt[v] = cnt[cur];
                        dis[v] = dis[cur] + 1;
                        q.push(v);
                    }
                }
            }
            for(int i = 1;i <= n;i++){
                if(cnt[i] == 2) ans++;
            }
        }
        cout<<(ans / 2)<<'\n';
    }
    return 0;
}
// g++ migrate.cpp -o migrate -std=c++14

/*
0 1
5 3
-3 0 2 3 4
*/