#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<ll> v;
ll ans = 0;
vector<bool> vis;
void dfs(ll k, ll sum) {
    if(k == m+1) {
        ans = max(ans, sum);
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(k+1, sum&v[i]);
            vis[i] = 0;
        }
    }
}
vector<int> cnt(100);
void exchange(int t) {
    int count = 1;
    while(t) {
        if(t&1) {
            cnt[count]++;
        }
        count++;
        t >>= 1;
    }
}
ll rechange(ll t) {
    ll ans = 0, a = 1;
    while(t) {
        if(cnt[t&1]-1 == 0) {
            ans += a;
        }
        a *= 2;
        t >>= 1;
    }
    return ans;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    v.resize(n+1);
    vis.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    if(n <= 20) {
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                vis[i] = 1;
                dfs(2, v[i]);
                vis[i] = 0;
            }
        }
        cout << ans << "\n";
    } else if(n <= 2000) {
        if(m == 1) {
            for(int i = 1; i <= n; i++) {
                ans = max(ans, v[i]);
            }
            cout << ans << "\n";
        } else if(m == 2) {
            for(int i = 1; i < n; i++) {
                for(int j = i+1; j <= n; j++) {
                    ans = max(ans, v[i]&v[j]);
                }
            }
            cout << ans << "\n";
        } else {
            ans = v[1];
            for(int i = 2; i <= n; i++) {
                ans &= v[i];
            }
            cout << ans << "\n";
        }
    } else {
        if(m == n-1) {
            ll t = v[1];
            for(int i = 1; i <= n; i++) {
                exchange(v[i]);
                ans &= v[i];
            }
            for(int i = 1; i <= n; i++) {
                ans = max(ans, t - rechange(v[i]));
            }
            cout << ans << "\n";
        } else {
            sort(v.begin(), v.end());
            bool flag = true;
            ll ma = 0, a = 0, b = 0, ma1 = 0;
            for(int i = 1; i <= n; i++) {
                ma = max(ma, v[i]);
                if(ma > v[i]) {
                    ma1 = ma;
                    ma = v[i];
                } else if(ma1 > v[i]) {
                    ma1 = v[i];
                }
                if(v[i] == 2) a++;
                if(v[i] == 3) b++;
                if(v[i] != i-1) {
                    flag = false;
                }
            }
            if(flag) {//特殊性质B
                cout << n-pow(2, floor(log2(m-1)+1)) << "\n";
            } else if(ma < 4) {
                if(b > m) cout << 3;
                else if(a+b > m) cout << 2;
                else cout << 0;
                cout << "\n";
            } else if(ma < pow(2ll, 20ll) && ma > pow(2ll, 10ll)) {//特殊性质A
                cout << ma << "\n";
            } else {
                int x = 0, y = 0;
                for(int i = 1; i <= n; i++) {
                    if(v[i] == ma) {
                        x++;
                    }
                    if(v[i] == ma1) {
                        y++;
                    }
                }
                if(x >= m) {
                    cout << ma;
                } else if(x + y >= m) {
                    cout << ma-1;
                } else {
                    cout << 0 << "\n";
                }
            }
        }
    }
    return 0;
}