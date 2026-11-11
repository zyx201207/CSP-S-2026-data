#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+10;
int n;
ll a[N];
char c[N];

void solve1() {
    string s = "";
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++) {
            s = s + c;
        }
    }
    int len = s.size();
    int r = 0, l = len - 1;
    while(r <= l) {
        if (s[r] != s[l]) {
            cnt++;
        }
        r++;
        l--;
    }
    cout << cnt;
}

void solve2() {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    int r = n, l = 1;
    while(l <= r) {
        if (c[r] == c[l]) {
            if (a[r] >= a[l]) {
                a[r] -= a[l];
                a[l] = 0;
                l++;
            } else {
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
        } else {
            if (a[r] >= a[l]) {
                a[r] -= a[l];
                cnt+=a[l];
                a[l] = 0;
                l++;
            } else {
                a[l] -= a[r];
                cnt += a[r];
                a[r] = 0;
                r--;
            }
        }
    }
    cout << cnt;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    if (n == 1) {
        cout << 0;
    } else if (n <= 10) {
        solve1();
    } else {
        solve2();
    }

    return 0;
}
