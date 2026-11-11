#include <bits/stdc++.h>
using namespace std;

int w[500055], k[505];
int a[505][500055], t[505][500055];
long long dis[505][505];
vector <int> v[500055];

int main(){
    //15:20:16 first finish(all tasks correct but all slow(1.2s+ T_T))
    //15:25:20 a little faster(subway6.in 1.25s -> 0.966s)(but subway7.in still 1.25s+)
    //15:34:49 tried scanf and printf and finally subway7.in 1.25s+ -> 0.970s(but i still need make it faster)
    //15:37:42 all faster than 1s but i still scared that aybe it will TLE(all 0.98/0.99s)
    //15:41:07 0.98s -> 0.68s(but wrong answer)
    //15:43:30 fixed!!! correct answer and less runtime :D(subway7.in 0.8s)
    //17:16:10 my computer break a little, and teacher comes and fix it
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    //ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n, m, d, q;
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1;i <= m;i++){
        scanf("%d", &w[i]);
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1;i <= n;i++){
        scanf("%d", &k[i]);
        for(int j = 1;j <= k[i];j++){
            scanf("%d", &a[i][j]);
            scanf("%d", &t[i][a[i][j]]);
            v[a[i][j]].push_back(i);
            for(auto p : v[a[i][j]]){
                dis[p][i] = min(dis[p][i], (long long)(1ll * t[p][a[i][j]] + 1ll * t[i][a[i][j]]));
            }
        }
    }
    //O(400K) MAX=2e8
    /*
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < v[i].size();j++){
            for(int k = j + 1;k < v[i].size();k++){
                dis[v[i][j]][v[i][k]] = min(dis[v[i][j]][v[i][k]], (long long)(1ll * t[v[i][j]][i] + 1ll * t[v[i][k]][i]));
            }
        }
    }
    */
    //floyd O(n^3) MAX=125000000=1.25e8
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                dis[j][k] = min(dis[j][k], dis[min(i, j)][max(i, j)] + dis[min(i, k)][max(i, k)]);
            }
        }
    }
    //output O(d^2*q) MAX=400*10^5=4e7
    int p1, p2;
    for(int i = 1;i <= q;i++){
        cin >> p1 >> p2;
        long long mn = 2e17;
        for(int j = 0;j < v[p1].size();j++){
            for(int k = 0;k < v[p2].size();k++){
                if(v[p1][j] == v[p2][k]){
                    mn = min(mn, (long long)(1ll * t[v[p1][j]][p1] + 1ll * t[v[p2][k]][p2]));
                }
                if(v[p1][j] > v[p2][k]) mn = min(mn, dis[v[p2][k]][v[p1][j]] + t[v[p1][j]][p1] + t[v[p2][k]][p2]);
                else mn = min(mn, dis[v[p1][j]][v[p2][k]] + t[v[p1][j]][p1] + t[v[p2][k]][p2]);
            }
        }
        printf("%lld\n", (mn + 1ll * w[p1] + 1ll * w[p2]));
        //cout << mn + 1ll * w[p1] + 1ll * w[p2] << "\n";
    }
    return 0;
}
