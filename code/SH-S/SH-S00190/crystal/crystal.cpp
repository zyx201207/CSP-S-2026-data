#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010

ll m;
int n, a[N], arr[N], dp[N];

bool canDo(ll st, ll ed) {
    ll value = 0;
    for (int i = st + 1; i <= ed; ++i) {
        value += arr[i] * (i - st);
        // cout << "<DEBUG> arr[" << i << "]:" << arr[i] << "\n";
        if (value > m) return false;
    }
    // cout << "<DEBUG> canDo(" << st << ", " << ed << ") returns true\n";
    return true;
}

void dynaProg() {
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int k = 1; k < i; ++k){
            if (canDo(k, i) * (i - k + 1) >= dp[i]) {
                dp[i] = canDo(k, i) * (i - k + 1);
                break;
            }
        }
        // cout << "<DEBUG> dp[" << i << "] = " << dp[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i]; 

    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i)
        arr[i] = a[i] - a[i - 1];

    dynaProg();
    cout << dp[n] << "\n";
    // cout << canDo(1, 4);
    return 0;
}