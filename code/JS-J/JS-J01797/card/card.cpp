#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500010], cnt[300010];
bool is[500010];
stack<ll> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++) {
        memset(is, false, sizeof(is));
        for (ll j = i; j <= n; j++) {
            if (!is[a[j]]) {
                st.push(a[j]);
                is[a[j]] = true;
            } else {
                while (1) {
                    if (st.top() == a[j]) {
                        break;
                    }
                    is[st.top()] = false;
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            cnt[st.top()]++;
            st.pop();
        }
    }
    for (ll i = 1; i <= m; i++) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
