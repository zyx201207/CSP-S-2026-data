#include <bits/stdc++.h>
using namespace std;
//priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int c, n ,m ,d, q;
long long a[50005];
bool b[505][50005];
long long cost[50005][505];
long long g[505][505];
long long dist[505][505];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <=m ;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int x = 0, y = 0;
            cin >> x >> y;
            cost[x][i] = y;
            b[i][x] = 1;
            for(int l = i - 1;l >= 1;l--){
                if(b[l][x]) {
                    if(g[i][l] != 0)
                    {
                        g[i][l] = min(cost[x][l] + cost[x][i], g[i][l]);
                        g[l][i] = min(cost[x][l] + cost[x][i], g[l][i]);
                    }
                    else{
                        g[i][l] = cost[x][l] + cost[x][i];
                        g[l][i] = cost[x][l] + cost[x][i];
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                if(dist[i][j] == 0)
                {
                    dist[i][j] = g[i][k] + g[k][j];
                    dist[j][i] = dist[i][j];
                    continue;
                }
                dist[i][j] = min(dist[i][j], g[i][k] + g[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }

    for(int i = 1;i <= q;i++){
        int st, ed;
        cin >> st >> ed;
        long long ans = 1 << 30;
        int j1 = st, k1 = st;
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(b[j][st] && b[k][ed]){
                    if(ans >= dist[j][k]){
                        if(j == k1 && k == j1){
                            if(cost[j1][st] + cost[k1][ed] < cost[j][st] + cost[k][ed])
                            {
                                j1 = j;
                                k1 = k;
                                continue;
                            }
                        }
                        j1 = j;
                        k1 = k;
                    }
                    ans = min(ans, dist[j][k]);
                }
            }
        }
        cout << ans + a[st] + cost[st][j1] + a[ed] + cost[ed][k1] << endl;
    }


    return 0;
}


