#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, a[N], c, t, d, minn, minnn, cnt, fa[5005][5005], ans[5005];
//vector <int> g[N];
void dfs(int w, int f, int c){
    if (w == f){
        if (minn > c){
            minn = c;
            minnn = 1;
        }
        else if (minn == c){
            minnn += 1;
        }
        return;
    }
    for (int i = 1; i <= ans[w]; i++){
        if (w == fa[w][i] || fa[w][i] > f) continue;
        dfs(fa[w][i], f, c + 1);
    }
    //for (auto x : g[w]){
    //    if (w == x || x > f) continue;
    //    dfs(x, f, c + 1);
    //}
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--){
        cnt = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
             cin >> a[i];
             ans[i] = 0;
        }
        for (int i = 1; i < n; i++){
            int j = i + 1;
            while (j <= n && a[j] - a[i] <= d){
                //g[i].push_back(j);
                fa[i][++ans[i]] = j;
                j++;
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = i + 3; j <= n; j++){
                minn = 1e9, minnn = 1;
                dfs(i, j, 0);
                if (minnn == 2)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
