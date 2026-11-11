#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 7;
constexpr int inf = 1e9;
int n, m, ans, maxn, mand, a[N], b[N];
bool flag, vis[N];
void dfs(int x, int sum, int res){
    if(sum == m){
        ans = max(ans, res);
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            sum++;
            int now = res;
            if(sum == 1) res = a[i];
            else res &= a[i];
            dfs(i, sum, res);
            res = now;
            sum--;
            vis[i] = false;
        }
    }
}
int calc(int x){
    int sum = 0;
    while(x > 0){
        sum++;
        x /= 2;
    }
    return sum - 1;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    maxn = -inf;
    flag = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
        if(i == 1) mand = a[i];
        else mand &= a[i];
        if(a[i] != i - 1) flag = false;
    }
    if(n == 1){
        cout << a[1] << '\n';
        return 0;
    }
    if(m == 1){
        cout << maxn << '\n';
        return 0;
    }
    if(m == n){
        cout << mand << '\n';
        return 0;
    }
    if(n <= 2000){
        dfs(0, 0, 0);
        cout << ans << '\n';
        return 0;
    }
    if(flag == true){
        int x = calc(n);
        sort(a + 1, a + n + 1, greater<int>());
        if(m <= x) cout << a[x] << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    sort(a + 1, a + n + 1, greater<int>());
    if(m == n - 1){
        for(int i = 1; i <= n - 1; i++){
            ans &= a[i];
        }
        cout << ans << '\n';
        return 0;
    }
    for(int i = 1; i <= m; i++){
        if(i == 1) ans = a[i];
        else ans &= a[i];
    }
    cout << ans << '\n';
    return 0;
}