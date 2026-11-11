#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int INF = 0x3f3f3f3f;
int a[N];
int dis[N][N];
int cnt[N][N];
void floyd(int n){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cnt[i][j] = 0;
            for(int k = 1;k <= n;k++){
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    cnt[i][j] = 1;
                    dis[i][j] = dis[i][k] + dis[k][j];
                }else if(dis[i][k] + dis[k][j] == dis[i][j]){
                    cnt[i][j]++;
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = abs(a[i] - a[j]) <= d ? abs(a[i] - a[j]) : INF;
            }
        }
        floyd(n);
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j){
                    continue;
                }
                if(cnt[i][j] == 2){
                    ans++;
                }
            }
        }
        cout << ans / 2 << '\n';
    }
    return 0;
}
