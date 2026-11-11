#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, d, a[2000001];
int profind(int l, int r, int pos, bool r1, bool r2){
    int ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (r1){
            if (abs(a[mid] - a[pos]) <= d){
                ans = mid;
                if (r2)
                    r = mid - 1;
                else
                    l = mid + 1;
            } else
                if (r2)
                    l = mid + 1;
                else
                    r = mid - 1;
        } else {
            if (abs(a[mid] - a[pos]) > d){
                ans = mid;
                if (r2)
                    r = mid - 1;
                else
                    l = mid + 1;
            } else
                if (r2)
                    l = mid + 1;
                else
                    r = mid - 1;
        }
    }
    return ans;
}
bool check(int i){
    if (a[i] - a[i - 3] > d && a[i] - a[i - 2] <= d && a[i - 1] - a[i - 3] <= d)
        return true;
    return false;
}
void solve(){
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 4; i <= n; i++)
        if (check(i)){
            int l1 = profind(1, i - 4, i, true, true), l2 = profind(1, i - 4, i, false, true);
            if (l1 != -1 && l2 != -1){
                int canl = i - 4 - max(l1, l2);
                ans += canl;
            }
            int r1 = profind(i + 1, n, i, true, false), r2 = profind(i + 1, n, i, false, false);
            if (r1 != -1 && r2 != -1){
                int canr = min(r1, r2) - i - 1;
                ans += canr;
            }
            ans++;
        }
    cout << ans << '\n';
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t, tag;
    cin >> tag >> t;
    while (t--)
        solve();
    return 0;
}
