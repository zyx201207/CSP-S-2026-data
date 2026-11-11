#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
long long k;
long long ans;
int w[500010];

long long dist[1010][1010];
struct {
    long long a[10];
    long long t[10];
}road[510];

void floyed() {
    for(int k = 1; k <=m; k++) {
        for(int x = 1; x <= m; x++) {
            for(int y = 1; y <= m; y++) {
                if(x == y) {
                    dist[x][y] = 0;
                    continue;
                }
                dist[x][y] = min(dist[x][y], dist[x][k] + dist[k][y]);
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i <= m; i++) {
        cin>>w[i];
    }
    /*
    for(int i = 1; i <= n; i++) {
        cin>>k;
        for(int j = 1; j <=k; j++) {
            cin>>road[k].a[k];
            cin>>road[k].t[k];
        }
    }
    */
    for(int i = 1; i <= n; i++) {
        cin>>k;
            for(int j = 1; j <=k; j++) {
                cin>>road[k].a[j];
                cin>>road[k].t[j];
            }
            dist[road[k].a[1]][road[k].a[2]] = min(road[k].t[1] + road[k].t[2], dist[road[k].a[1]][road[k].a[2]]);
            dist[road[k].a[2]][road[k].a[1]] = min(road[k].t[1] + road[k].t[2], dist[road[k].a[2]][road[k].a[1]]);
    }
    floyed();
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin>>x>>y;
        cout<<dist[x][y] + w[x] + w[y]<<endl;
    }
    return 0;
}
