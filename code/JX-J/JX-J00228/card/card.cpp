#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
ll n, m, a[MAXN], sum[MAXN];
bool vis[MAXN];
stack<ll> str;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        memset(vis, false, sizeof(vis));
        for(int j = i + 1; j <= n; j ++) {
            if(vis[a[j]] == true) {
                while(!str.empty()) {
                    if(str.top() == a[i]) {
                        str.pop();
                        vis[str.top()] = false;
                        break;
                    }
                    vis[str.top()] = false;
                    str.pop();
                }
            }
            str.push(a[j]);
            vis[a[j]] = true;
        }
        while(!str.empty()) {
            sum[str.top()] ++;
            str.pop();
        }
    }
    for(int i = 1; i <= m; i ++) {
        cout << sum[i] << " ";
    }
    return 0;
}
