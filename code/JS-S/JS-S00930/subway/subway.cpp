#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int c, n, m, d, q, k, p, s, e;
int ans;
int w[N], a[505][N], vis[N];
void bfs(int pos, int cnt){
    if(pos == e){
        ans = min(ans, cnt);
        return;
    }
    vis[pos] = 1;
    for(int i = 1;i <= n;i ++){
        if(a[i][pos]){
            for(int j = 1;j <= m;j ++){
                if(a[i][j] && !vis[j]){
                    bfs(j, cnt + a[i][pos] + a[i][j]);
                }
            }
        }
    }
    vis[pos] = 0;
}
int main(){
    freopen("subway3.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for(int i = 1;i <= m;i ++){
        scanf("%d", &w[i]);
    }
    for(int i = 1;i <= n;i ++){
        scanf("%d", &k);
        for(int j = 1;j <= k;j ++){
            scanf("%d", &p);
            scanf("%d", &a[i][p]);
        }
    }
    while(q --){
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &s, &e);
        ans = INT_MAX;
        bfs(s, 0);
        printf("%d\n", ans + w[s] + w[e]);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
