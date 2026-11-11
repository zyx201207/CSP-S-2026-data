#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500001], s[500001];
bool check(int k) {
    for(long long l = 1; l <= n - k + 1; l++) {
        long long r = l + k - 1;
        long long cnt = a[r] * k - (s[r] - s[l - 1]);
        if(cnt <= m)
            return true;
    }
    return false;
}
int main() {
    //Give me a blue-gou pls,I'll do every thing
    //By Luogu-bilibiliTV
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    long long l = 0, r = n, mid, ans = 0;
    while(l <= r) {
        mid = l + r >> 1;
        bool tf = check(mid);
        if(tf) {
            ans = max(ans, mid);
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
    return 0;
}
