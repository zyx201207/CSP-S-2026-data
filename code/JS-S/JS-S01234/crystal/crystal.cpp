#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//fo zu bao you, bu yao bao ling

const int N = 5e5 + 5;

ll a[N];
ll n, m;
bool check(int num) {
    ll sum = 0, ans = 0;
    for (int i = 1; i <= num; i++) {
        sum += a[num] - a[i];
    }
    ans = sum;
    for (int i = num + 1; i <= n; i++) {
        sum += (a[i] - a[i - 1]) * num; 
        sum -= (a[i] - a[i - num]);
        ans = min(sum, ans);
    }
    return ans <= m;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    //freopen("t.txt", "w", stderr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //cout << a[i];
    }
    sort(a + 1, a + n + 1);
    //for (int i = 1; i <= n; i++) {
    //    cerr << a[i] << ' ';
    //}
    ll l = 1, r = n;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    //cerr << check(r + 1);
    cout << r;
    return 0;
}
