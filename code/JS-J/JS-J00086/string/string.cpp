#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    string s;
    ll n;
    cin >> n;
    vector<char> v;
    vector<ll> idx;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        char c;
        ll num;
        cin >> num >> c;
        sum += num;
        v.push_back(c);
        idx.push_back(sum);
    }

    ll ans = 0;
    for (ll i = sum / 2; i < sum; i ++) {
        ll idx_a = upper_bound(idx.begin(), idx.end(), i) - idx.begin();
        ll idx_b = upper_bound(idx.begin(), idx.end(), sum - i - 1) - idx.begin();
        char c_a = v[idx_a];
        char c_b = v[idx_b];
        ans += (c_a == c_b ? 0 : 1);
    }
    cout << ans << endl;
    return 0;
}
