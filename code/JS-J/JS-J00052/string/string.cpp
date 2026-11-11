#include<bits/stdc++.h>
using namespace std;

char c[200005], ct;
int f;
int az[200005][3];


int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long a, t = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> c[i];
        t += a;
        az[i][1] = a;
        az[i][2] = c[i] - '0';
    }
    for (int i = 2; i <= n; i++) {
        if (c[i] != c[i-1]) {
            f = 1;
        }
    }
    if (f == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int mid = t/2;
    int cnt = 0;
    int l = 1, r = n;
    int cnt1 = 0;
    while (1) {
        if (az[l][2] != az[r][2]) {
            az[l][1] -= min(az[l][1], az[r][1]);
            az[r][1] -= min(az[r][1], az[l][1]);
            cnt1 += min(az[l][1], az[r][1]);
            mid -= az[l][1];
        } else {
            az[l][1] -= min(az[l][1], az[r][1]);
            az[r][1] -= min(az[l][1], az[r][1]);
            cnt += min(az[l][1], az[r][1]);
            mid -= az[l][1];
        }
        if (az[l][1] == 0) {
            l += 1;
        }
        if (az[r][1] == 0) {
            r -= 1;
        }
        if (mid <= 0) {
            break;
        }
    }
    cout << t/2 - cnt << '\n';
    return 0;
}
