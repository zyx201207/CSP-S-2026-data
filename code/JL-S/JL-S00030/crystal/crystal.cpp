#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, cnt1 = 1, cnt2 = 1;
long long m;
long long a[N];
bool cmp(int a, int b) {
    return a <= b;
}
long long abs_(long long x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n, cmp);
    long long mid = (a[1] + a[n]) / 2;
    int c = N, k = 0;
    for (int i = 1; i <= n; i ++) {
        if (abs_(mid - a[i]) < c) {
            c = mid - a[i];
            k = i;
        }
    }
    int c2 = N, k2 = 0;
    for (int i = 1; i <= n; i ++) {
        if (abs_(mid - a[i]) <= c2) {
            c2 = mid - a[i];
            k2 = i;
        }
    }
    long long m1 = m;
    for (int i = k; i > 0; i --) {
        if (m > (mid - a[i])) {
            m -= (mid - a[i]);
            cnt1 ++;
        }
    }
    for (int i = k2; i > 0; i --) {
        if (m1 > (mid - a[i])) {
            m1 -= (mid - a[i]);
            cnt2 ++;
        }
    }
    cout << max(cnt1, cnt2);
    return 0;
}
