#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int y[N];
int dist[10005][10005];
int b[10005][10005];
bool st[N];
int c, n, m, d, q;

void dijistra(){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        st[u] = 0;
        for(int i = 1; i <= m; i ++ ){
            if(i == u) continue;
            if(dist[u][0] + dist[0][i] < dist[u][i]){
                dist[u][i] = dist[u][0] + dist[0][i];
                if(!st[i]) q.push(i);
                st[i] = 1;
            }
        }
    }
}

int main(){
    memset(dist, 0x3f, sizeof dist);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++ ){
        cin >> y[i];
    }
    for(int i = 1; i <= n; i ++ ){
        int k;
        cin >> k;
        for(int j = 1; j <= k ; j ++ ){
            int c;
            cin >> b[i][j] >> c;
            b[i][0] = k;
            dist[0][b[i][j]] = dist[b[i][j]][0] = c;
        }
        for(int j = 1; j <= k; j ++ ){
            for(int t = 1; t < j; t ++ )
                dist[b[i][j]][b[i][t]] = dist[b[i][t]][b[i][j]] = 0;
        }
    }
    dijistra();
    for(int i = 1; i <= q; i ++ ){
        int a, b;
        cin >> a >> b;
        cout << y[a] + dist[a][0] + dist[0][b] + y[b] << endl;
    }

    return 0;
}
