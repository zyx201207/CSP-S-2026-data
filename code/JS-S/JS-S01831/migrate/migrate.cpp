#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

const int N = 5005, INF = 1e9;
int n, d;
int x[N];
int dis[N][N];
vector<pair<int, int>> g[N];


int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = read(), t = read();
    while(t--){
        n = read(), d = read();
        for(int i = 1;i <= n;i++) x[i] = read();
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = x[i] - x[j];
                if(dis[i][j] > d || dis[i][j] < 0) dis[i][j] = INF;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                    cout << dis[i][j] << ' ';
            }
            cout << '\n';
        }
        int ans = 0;
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(dis[i][k] >= INF/2 || dis[k][j] >= INF/2) continue;
                    if(dis[i][j] > dis[i][k] + dis[k][j]){
                        cnt[i][j] = 1;
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }else if(dis[i][j] == dis[i][k] + dis[k][j]){
                        cnt[i][j]++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
