#include<bits/stdc++.h>
using namespace std;
struct place{
    int in;
    int v[500];
}p[2001];
int d[2001][2001];
map<pair<int,int>, bool> mp;
int c, n, m, D, q, op, xr, yr;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &D, &q);
    for(int i=1; i<=m; i++) scanf("%d", &p[i].in);
    for(int i=1; i<=n; i++){
        int K;
        scanf("%d", &K);
        for(int j=0; j<K; j++){
            scanf("%d", &op);
            scanf("%d", &p[op].v[i]);
            mp[{op,i}] = true;
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            d[i][j] = 1e9;
        }
        d[i][i] = 0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=n; k++){
                if( mp[{i, k}] && mp[{j, k}] ){
                    d[i][j] = min(d[i][j], p[i].v[k] + p[j].v[k]);
                }
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=m; k++){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    for(int i=0; i<q; i++){
        scanf("%d%d", &xr, &yr);
        printf("%d\n", d[xr][yr]+ p[xr].in + p[yr].in);
    }
    return 0;
}
