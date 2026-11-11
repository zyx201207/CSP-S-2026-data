#include <bits/stdc++.h>
#define int long long
using namespace std;

int T = 1;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int arr[N];
int ans[M];
int dp[N];
stack<int> st;
bool appear[M];

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = n; i >= 1; i--) {
        if (appear[arr[i]]) {
            while (arr[st.top()] != arr[i]) {
                appear[arr[st.top()]] = false;
                st.pop();
            }
        } else {
            appear[arr[i]] = true;
            st.push(arr[i]);
        }
        dp[i] = dp[st.top()] + 1;
    }
    for (int i = 1; i <= n; i++) {
        ans[arr[i]] = max(ans[arr[i]], dp[i]);
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (T--) {
        Solve();
    }
    return 0;
}
