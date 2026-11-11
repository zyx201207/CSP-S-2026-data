#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int N = 5e5 + 10;
using ll = long long;

ll n, m;
ll a[N];
ll head = 1, tail = 0, q[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ll sum = 0, ans = 1;
    for (ll i = 1; i <= n; ++i){
        sum += (i-head) * (a[i]-a[i-1]);
        while (head <= tail && sum > m) {
            head++;
            sum -= a[i]-a[head];
        }
        q[++tail] = i;
        ans = max(ans, i-head+1);
    }
    cout << ans;
    return 0;
}
