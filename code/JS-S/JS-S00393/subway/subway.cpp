#include <bits/stdc++.h>
using namespace std;

int ans,n,m,d,q,k[505],extt[500005];
int mp[505][505],minmp[505][505];
pair <int,int> w;
vector <pair<int,int>> edge[500005];
vector <pair<int,int>> edges[505];

inline void dfs(int st,int x,int cnt){
    minmp[st][x] = cnt;
    for(auto j : edges[x]){
        int j1 = j.first,j2 = j.second;
        if(minmp[st][j1] > cnt+j2){
            dfs(st,j1,cnt+j2);
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i = 0;i <= 500;i++){
        for(int j = 0;j <= 500;j++){
            mp[i][j] = 1e9;
            minmp[i][j] = 1e9;
        }
    }
    scanf("%d%d%d%d%d",&n,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++){
        scanf("%d",&extt[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",&k[i]);
        for(int j = 1;j <= k[i];j++){
            int x,y;scanf("%d%d",&x,&y);
            w.first = i;w.second = y;
            edge[x].push_back(w);
        }
    }
    for(int i = 1;i <= m;i++){
        for(auto j : edge[i]){
            for(auto k : edge[i]){
                int x = j.first,y = k.first;
                if(x != y){
                    mp[x][y] = min(mp[x][y],j.second+k.second);
                }
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = i+1;j <= m;j++){
            if(mp[i][j] != 1e9){
                edges[i].push_back({j,mp[i][j]});
                edges[j].push_back({i,mp[i][j]});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        dfs(i,i,0);
    }
    for(int i = 1;i <= q;i++){
        ans = INT_MAX;
        int x,y;scanf("%d%d",&x,&y);
        for(auto j1 : edge[x]){
            for(auto j2 : edge[y]){
                if(minmp[j1.first][j2.first] == 1e9){
                    continue;
                }
                ans = min(ans,j1.second+j2.second+minmp[j1.first][j2.first]);
            }
        }
        ans += extt[x]+extt[y];
        printf("%d\n",ans);
    }
}
