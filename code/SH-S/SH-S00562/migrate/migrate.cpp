#include<bits/stdc++.h>
using namespace std;

void io() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

using ll = long long;
const ll MX = 2e6 + 10;

ll n, d, x[MX];
deque<ll> q;
ll dis[5005][5005], means[5005][5005];
void t10() {
    cin >> n >> d;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (ll i = 1; i <= n - 1; ++i) {
        q.clear();
        dis[i][i] = 0;
        means[i][i] = 1;
        means[i][i - 1] = 0;
        q.push_back(i);
        for (ll j = i + 1; j <= n; ++j) {
            while (q.size() && x[j] - x[q.front()] > d) q.pop_front();
            if (q.empty()) {
                while (j <= n) {
                    means[i][j] = 0;
                    ++j;
                }
                break;
            }
            q.push_back(j);
            dis[i][j] = dis[i][q.front()] + 1;
            ll k = lower_bound(dis[i] + i, dis[i] + j, dis[i][q.front()] + 1) - dis[i] - 1;
//            cout << dis[i][q.front()] << ' ' << dis[i][k] << ' ' << dis[i][k + 1] << '\n';
//            for (ll k = q.front(); k < j; ++k) {
//                if (dis[i][k] == dis[i][q.front()]) means[i][j] += means[i][k];
//          }
            means[i][j] = means[i][k] - means[i][q.front() - 1] + means[i][j - 1];
        }
//        cout << '\n';
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
//        for (ll j = 1; j <= i; ++j) {
//            cout << means[i][j] << ' ';
//        }
        for (ll j = i + 1; j <= n; ++j) {
//            cout << means[i][j] << ' ';
            if (means[i][j] - means[i][j - 1] == 2) ++ans;
        }
//        cout << '\n';
    }
    cout << ans << endl;
}

void tA() {
    cin >> n >> d;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    ll dx = x[2] - x[1];
    ll sx = d / dx;
    if (sx <= 1) {
        cout << 0 << '\n';
        return;
    }
    cout << max(n - (2 * sx - 1), 0ll) << '\n';
}

void tB() {
    cin >> n >> d;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ll far = lower_bound(x + 1, x + n + 1, x[i] + d + 1) - x;
        ll x3 = lower_bound(x + 1, x + n + 1, x[far - 3] + d + 1) - x;
        ll x2 = lower_bound(x + 1, x + n + 1, x[far - 2] + d + 1) - x;
        ans += x2 - x3;
    }
    cout << ans << '\n';
}

int main() {
    
    io();

    ll c, t;
    cin >> c >> t;
    while (t--) {
        if (c <= 10) {
            t10();
            continue;
        }
        if (c == 11 || c == 12) {
            tA();
            continue;
        }
        if (c == 13 || c == 14) {
            tB();
            continue;
        }
    }

	cout.flush();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
