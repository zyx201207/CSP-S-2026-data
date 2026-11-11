#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n+1);
    if(n <= 500) {
        vector<ll> card(n+1), cnt(m+1, 0);
        vector<bool> vis(m+1, 0);
        for(int i = 1; i <= n; i++) {
            ll len = 0;
            card.clear();
            for(int j = i; j <= n; j++) {
                if(vis[v[j]]) {
                    for(int pos = 1; pos <= len; pos++) {
                        if(card[pos] == v[j]) {
                            len = pos-1;
                            break;
                        }
                    }
                }
                card[++len] = v[j];
                vis[v[j]] = 1;
            }
            for(int j = 1; j <= len; j++) {
                cnt[card[j]]++;
            }
        }
        for(int i = 1; i <= m; i++) {
            cout << cnt[i] << " ";
        }
        cout << "\n";
    } else {
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        vector<ll> pos(m+1), cnt(m+1);
        for(int i = 1; i <= n; i++) {
            pos[v[i]] = i;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                cnt[v[j]]++;
                j = pos[v[j]];
            }
        }
        for(int i = 1; i <= m; i++) {
            cout << cnt[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}