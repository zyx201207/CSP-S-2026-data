#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200007;
const int M = 100007;

int n, m;
int a[N];
stack<int> st;
bool cnt[M];
int ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j <= n; j++) {
            if (cnt[a[j]] == 0) {
                st.push(a[j]);
                cnt[a[j]] = 1;
            } else {
                while(st.top() != a[j]) {
                    cnt[st.top()] = 0;
                    st.pop();
                }
            }
        }
        for (int j = 1; j <= m; j++) {
            ans[j] += cnt[j];
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}