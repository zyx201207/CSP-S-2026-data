#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5;
int n, m;
int a[N + 10], ans[N + 10];
stack<int> st;
bool in[3010];
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        memset(in, 0, sizeof in);
        for (int j = i; j <= n; j ++) {
            if (in[a[j]]) {
                while(st.top() != a[j] && st.size()) {
                    in[st.top()] = 0;
                    st.pop();
                }
                in[a[j]] = 1;
            }
            else {
                in[a[j]] = 1;
                st.push(a[j]);
            }
        }
        for (int i = 1; i <= m; i ++)  ans[i] += in[i];
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
