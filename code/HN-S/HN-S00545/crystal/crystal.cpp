#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], s[N];
inline bool check(int i, int mid) {
    return (mid - i) * a[i] - (s[mid] - s[i]) <= m;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int lt = i, rt = n + 1;
        while(lt + 1 < rt) {
            int mid = lt + rt >> 1;
            if(check(i, mid)) lt = mid;
            else rt = mid;
        }
        res = max(res, lt - i + 1);
    }
    cout << res;
    return 0;
}
/*
乐扣保佑！！！！！！
*/