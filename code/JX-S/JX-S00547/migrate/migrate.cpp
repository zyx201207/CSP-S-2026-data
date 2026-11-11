#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, d, X[200005], c[2005], minn, ans;
void dfs(int x, int y, int s){
    if (x == y){
        minn = min(minn, s);
        c[s] ++;
        return ;
    }
    int sum = 0;
    for (int i = x + 1; i <= y; i ++){
        sum += abs(X[i] - X[i-1]);
        if (sum > d) break;
        dfs(i, y, s + 1);
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int C, T;
    cin >> C >> T;
    while (T --){
        cin >> n >> d;
        for (int i = 1; i <= n; i ++){
            cin >> X[i];
        }
        for (int i = 1; i <= n; i ++){
            for (int j = i + 1; j <= n; j ++){
                memset(c, 0, sizeof c);
                dfs(i, j, 0);
                if (minn == 1e18) continue;
                if (c[minn] == 2) ans ++;
                minn = 1e18;
            }
        }
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}
