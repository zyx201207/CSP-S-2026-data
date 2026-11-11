#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
ll cnt[N];
char c[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cnt[i] >> c[i];
    ll ans = 0;
    for (int i = 1, j = n; i < j; ) {
        if (cnt[i] < cnt[j]) {
            if (c[i] != c[j]) ans += cnt[i];
            cnt[j] -= cnt[i];
            i++;
        }
        else if (cnt[i] > cnt[j]) {
            if (c[i] != c[j]) ans += cnt[j];
            cnt[i] -= cnt[j];
            j--;
        }
        else {
            if (c[i] != c[j]) ans += cnt[j];
            i++, j--;
        }
    }
    cout << ans;
    return 0;
}

