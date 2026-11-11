#include <bits/stdc++.h>
#define int long long
using namespace std;

int T = 1;
const int N = 2e5 + 10;
int n;
int arr[N];
char ch[N];

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> ch[i];
    }
    int ans = 0;
    int now_l = arr[1], now_r = arr[n];
    for (int i = 1, j = n; i <= j; ) {
        if (ch[i] == ch[j]) {
            if (now_l > now_r) {
                now_l -= now_r;
                j--;
                now_r = arr[j];
            } else if (now_l < now_r) {
                now_r -= now_l;
                i++;
                now_l = arr[i];
            } else {
                i++;
                j--;
                now_l = arr[i];
                now_r = arr[j];
            }
        } else {
            if (now_l > now_r) {
                ans += now_r;
                now_l -= now_r;
                j--;
                now_r = arr[j];
            } else if (now_l < now_r) {
                ans += now_l;
                now_r -= now_l;
                i++;
                now_l = arr[i];
            } else {
                ans += now_l;
                i++;
                j--;
                now_l = arr[i];
                now_r = arr[j];
            }
        }
    }
    cout << ans;
}

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (T--) {
        Solve();
    }
    return 0;
}
