#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int pre[N];
int nxt[N];
bool l[N];
int a[N];
int ans[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int k = 1; k <= n; k ++) {
        for (int i = k; i <= n; i ++) {
            pre[i] = i-1;
            nxt[i] = i+1;
        }
        for (int i = 1; i <= m; i ++) l[i] = false;
        for (int i = k; i <= n; i ++) {
            pre[i] = i-1;
            nxt[i] = i+1;
            if (l[a[i]]) {
                int pos = i-1;
                while (true) {
                    l[a[pos]] = false;  // die
                    if (a[pos] == a[i]) break;
                    pos = pre[pos];
                }
                pre[i] = pre[pos];
                nxt[pre[i]] = i;
            }
            l[a[i]] = true;
        }
        for (int i = n; i >= k; i = pre[i]) {
            //cerr << a[i] << ' ';
            ans[a[i]] ++;
        }
        //cerr << '\n';
    }
    for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
