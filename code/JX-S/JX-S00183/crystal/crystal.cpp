#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5e5 + 5;
const int P = 1e9 + 7;
int n, m, ans;
int a[N], sum[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l <= r){
            int mid = (l + r) >> 1;
            int len = i - mid + 1;
            if(len * a[i] - sum[i] + sum[mid - 1] <= m) ans = max(ans, len), r = mid - 1;
            else l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
