#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
vector<ll> a(200005);

ll count_nums_of_one(ll num) {
    ll ret = 0;
    while(num) {
        if(num & 1) ret++;
        num >>= 1;
    }
    return ret;
}
ll num_idx(ll num) {
    ll ret = 0;
    while (num) {
        ret++;
        num >>= 1;
    }
    return ret;
}
string _turn(ll num) {
    string ret = "";
    while(num) {
        ret += num % 2 + '0';
        num /= 2;
    }
    return ret;
}
bool highest_one(ll num1, ll num2) {
    ll l = num_idx(num1);
    ll ret = 0;
    string _num1 = _turn(num1), _num2 = _turn(num2);
    for(int i = l-1; i >= 0; i--) {
        if (_num1[i] != _num2[i]) {
            if (_num1[i]-'0' > _num2[i]-'0') {
                return true;
            }
        }
    }
    return false;
}

bool cmp(ll num1, ll num2) {
    if (count_nums_of_one(num1) != count_nums_of_one(num2)) {
        return num1 > num2;
    }
    return num1 > num2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    ll ans = a[0];
    for(int i = 1; i < m; i++) {
        ans &= a[i];
    }
    cout << ans << endl;

    return 0;
}
