#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 6;
const int INF = 1e8;
int c,n,m,d,q;
int dis[MAXN][MAXN];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    int N = m*2 + n;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j){
               dis[i][j] = 0;
               continue;
            }
            dis[i][j] = INF;
        }
    }
    for(int i=1;i<=m;i++){
        int w;cin >> w;
        dis[i][i+m] = w;
        dis[i+m][i] = w;
    }

    for(int i=1;i<=n;i++){
        int cnt = 0; cin >> cnt;
        for(int j=1;j<=cnt;j++){
                int x,t;
            cin >> x >> t;
            dis[2*m+i][x] = t;
            dis[x][2*m+i] = t;
        }
    }
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << dis[u+m][v+m] << "\n";
    }
    return 0;
}
