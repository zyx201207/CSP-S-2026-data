#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[500005];
ll ans[300005];
ll cnt[300005], cnt1[300005];
ll last[300005], last2[300005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt1[a[i]]++;
        last[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        if (i == last[a[i]]) continue;
        else if (last2[a[i]] == 0) last2[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt[j] = cnt1[j];
        }
        for (int j = i; j <= n; j++) {
            if (cnt[a[j]] > 1 && cnt[a[j]] % 2 == 0) {
                for (int k = j; k < last[a[j]]; k++) {
                    cnt[a[k]]--;
                }
                j = last[a[j]] - 1;
            }
            else if (cnt[a[j]] > 2 && cnt[a[j]] % 2 == 1) {
                for (int k = j; k < last2[a[j]]; k++) {
                    cnt[a[k]]--;
                }
                j = last2[a[j]] - 1;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (cnt[j] > 0) ans[j]++;
        }
        cnt1[i]--;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}