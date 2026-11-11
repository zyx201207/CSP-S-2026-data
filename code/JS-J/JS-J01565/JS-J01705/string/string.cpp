#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

ll n, ans = 0;
vector<pair<ll, char>> a;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; i++) {
        ll cnt;
        char ch;
        cin >> cnt >> ch;

        a.push_back({cnt, ch});
    }

    ll l = 0, r = a.size();
    while(l < r) {
        if(a[l].first == 0) l++;
        if(a[r].first == 0) r--;
        ll x = min(a[l].first, a[r].first);
        if(!(a[l].second == a[r].second)) ans += x;
        a[l].first -= x;
        a[r].first -= x;
    }
    cout << ans << endl;
    return 0;
}
