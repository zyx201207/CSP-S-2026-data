#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], b[N], ans = 1;
bool cmp(int x, int y){
    return x > y;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    int s = a[2] - a[1], f = 1;
    for (int i = 3; i <= n; i++){
        if (a[i - 1] - a[i] != s){
            f = 0;
            break;
        }
    }
    for (int i = 1; i <= n; i++){
        b[i] = (i == 1 ? 0 : a[i - 1] - a[i]);
        b[i] = b[i - 1] + b[i];
    }
    if (f == 1){
        int sum = 0;
        for (int i = 2; i <= n; i++){
            sum += b[i];
            if (sum <= m) ans++;
            else break;
        }
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        int sum = 0, res = 1;
        for (int j = i + 1; j <= n; j++){
            sum += b[j] - b[i];
            if (sum <= m) res++;
            else break;
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}