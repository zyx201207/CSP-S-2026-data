#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
const int INF = 1e18;
int n, m, a[maxn], mx = -INF;
bool flag1 = true, flag2 = true;
signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        if(i > 2 && a[i] - a[i - 1] != a[2] - a[1]) flag2 = false;
        mx = max(mx, a[i]);
    }
    if(flag2) {
        int d = a[2] - a[1];
        int l = 1, r = n;

        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(m >= (d + a[mid] - a[1]) * (mid - 1) / 2) l = mid + 1;
            else r = mid - 1;
        }
        cout << r;
        return 0;
    }
    else{
        for(int i = 1; i <= n; i++) {
            int k = m, sum = 1;
            for(int j = i - 1; j >= 1; j--) {
                int d = a[i] - a[j];
                if(k >= d) {
                    k -= d;
                    sum++;
                }
                else break;
            }
            mx = max(mx, sum);
        }
        cout << mx;
        return 0;
    }
    return 0;
}
