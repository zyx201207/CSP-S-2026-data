#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 5e3+10;

int c,n,m,d,q;
int w[M];
int a[N][M];
int t[N][M];
long long dist[M][M];
long long res = 0;

void floyd(){
    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(k != i && k != j) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    bool flag2 = true;
    int T;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> a[i][j] >> t[i][j];
            t[j][i] = t[i][j];
            if(i == 1 && j == 1) T = t[i][j];
            if(t[i][j] != T) flag2 = false;
        }
    }
    if(flag2){
        for(int i = 1; i <= q; i++){
            int x,y;
            cin >> x >> y;
            res = w[x] + t[x][x] + t[x][y] + w[y];
            cout << res << 'n';
        }
    } else{
        memset(dist,0x3f,sizeof(dist));
        for(int i = 1; i <= m; i++){
            dist[i][i] = 0;
            for(int j = 1; j <= m; j++){
                if(i == j) continue;
                dist[i][j] = w[i] + t[i][i] + t[i][j] + w[j];
            }
        }
        floyd();
        for(int i = 1; i <= q; i++){
            int x,y;
            cin >> x >> y;
            cout << dist[x][y] << '\n';
        }
    }
    return 0;
}
