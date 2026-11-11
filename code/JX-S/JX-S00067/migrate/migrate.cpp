#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, n, d, a[N];
struct sb { int l, r; };
vector<sb> line;
void work() {
    int ans = 0;
    cin >> n >> d;
    line.clear();
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n <= 2) { cout << 0 << "\n"; return ; }
    if(c == 11 || c == 12) {
        if(a[3] - a[1] > d) {
            cout << 0 << "\n";
            return ;
        }
        if(a[3] - a[1] <= d && a[4] - a[3] > d) {
            cout << n - 3 << "\n";
            return ;
        }
        cout << 0 << "\n";
        return ;
    }
    for(int r = 4; r <= n; r++) {
        int l = r - 3;
        if(a[r] - a[l] > d && a[r - 1] - a[l] <= d && a[r] - a[l + 1] <= d) line.push_back({l, r});
    }
    for(int i = 0; i < line.size(); i++) {
        int l = line[i].l, r = line[i].r;
        while(l > 2) {
            if(a[l] - a[l - 2] > d && a[l] - a[l - 1] <= d) l--;
            else break;
        }
        while(r < n - 1) {
            if(a[r + 2] - a[r] > d && a[r + 1] - a[r] <= d) r++;
            else break;
        }
        //cout << l << " " << r << "\n";
        ans += (line[i].l - l + 1) * (r - line[i].r + 1);
    }
    cout << ans << "\n";
    return ;
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t; cin >> c >> t;
    while(t--) work();
    return 0;
}