// 100pts
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int kMaxN = 5e5 + 5;

int n, k, a[kMaxN];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1, j = 1, sum = 0; i <= n; i++) {
        sum += (i - j) * (a[i] - a[i - 1]);
        while(sum > k && j < i) {
            sum -= (a[i] - a[j++]);
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';
    return 0;
}

// ulimit -s 102400 && g++ -Wall -Wextra -O2 -std=c++14 crystal.cpp -o crystal && time ./crystal