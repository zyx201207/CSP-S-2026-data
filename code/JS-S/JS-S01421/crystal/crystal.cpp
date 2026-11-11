#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
long long m, a[N], s[N];
int ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) {
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1;i <= n;i++) {
        int l = 1, r = i - 1, mid;
        while(l <= r) {
            if(l == r) {
                mid = l;
                if(mid * a[i] + s[i - mid - 1] <= m + s[i - 1]) {
                    ans = max(ans, mid + 1);
                }
                break;
            }
            mid = (l + r + 1) / 2;
            if(mid * a[i] + s[i - mid - 1] > m + s[i - 1]) {
                r = mid - 1;
            }
            else if(mid * a[i] + s[i - mid - 1] == m + s[i - 1]) {
                ans = max(ans, mid + 1);
                break;
            }
            else {
                l = mid;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
