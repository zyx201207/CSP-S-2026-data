#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int mans;
int a[200050];

// vector<int>vis;
// void dfs(int step, int ans) {
//     if(step == m) {
//         mans = max(ans, mans);
//     }
    
//     for(int i = 1; i <= n; ++i) {
//         if(step == 0) ans = a[i];
//         if(!vis[i]) {
//             vis[i] = true;
//             dfs(step+1,ans & a[i]);
//             vis[i] = false;
//         }
//     }
// }
int main() {

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    // vis.resize(n + 2, true);
    int nummax = -1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        nummax = max(a[i],nummax);
    }

    if(m == 1) {
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[0] << '\n';
        return 0;
    }
    if(m == 2) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j)continue;
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans << '\n';
        return 0;
    }
    if(m == n) {
        int ans = a[1];
        for(int i = 1; i <= n; ++i) {
            ans &= a[i];
        }
        cout << ans << '\n';
        return 0;
    }
    if(m == n - 1) {
        int ans = 0;
        for(int k = 1; k <= n; ++k) {
            int tmp;
            if(k == 1)tmp = a[2];
            else tmp = a[1]; 
            for(int i = 1; i <= n; ++i) {
                if(i == k) continue;
                tmp &= a[i];
            }
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
        return 0;
    }
    if(n <= 2000) {
        vector<vector<int>>dp(n + 2,vector<int>(m + 2, 0));
        for(int i = 1; i <= n; ++i) {
            dp[i][1] = a[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 2; j <= m; ++j) {
                dp[i][j] = max(dp[i-1][j-1] & a[i], dp[i-1][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
    else {
        sort(a + 1, a + n + 1,greater<int>());
        int ans = a[1];
        for(int i = 2; i <= m; ++i) {
            ans &= a[i];
        }
        cout << ans << '\n';
        return 0;
    }
    return 0;
}