#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
const int N = 5e5 + 10;
int w[N];
int a[510][N], t[510][N];
/*
int g[N][25], b[N];
int minn_ans = INT_MAX;
void bfs(int x, int en, int minn) {
    if(x == en) {
        minn_ans = min(minn_ans, minn);
        return ;
    }
    for(int i = 1; i <= b[x]; i++) {
        bfs(g[x][i], en, minn + 1);
    }
}
*/
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            cin >> a[i][j] >> t[i][j];
            //b[a[i][j]]++;
            //g[a[i][j]][b[a[i][j]]] = a[i][j - 1];
        }
    }
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        //bfs(l, r, 0);
        //cout << minn_ans << endl;
        cout << (r - l) * t[1][1] + w[l] + w[r] << endl;
    }
    
    return 0;
}
//so that, does CFF won?