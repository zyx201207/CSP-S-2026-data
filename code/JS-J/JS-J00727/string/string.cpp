#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long l[200005], r[200005];
long long cnt[30][200005];
void write(__int128 x) {
    if (x == 0) {
        puts("0");
        return;
    }
    string s = "";
    while (x > 0) {
        s += (x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
void solve2() {
    __int128 ans = 0;
    long long tmp = 1;
    long long Len = 0;
    for (int i = 1; i <= n; i++) {
        l[i] = tmp;
        r[i] = l[i] + a[i] - 1;
        tmp = r[i] + 1;
        Len += a[i];
        for (int j = 0; j < 26; j++) {
            cnt[j][i] = cnt[j][i - 1] + a[i] * (j == c[i] - 'a');
        }
        //cout << l[i] << ' ' << r[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        long long Left = Len - r[i] + 1, Right = Len - l[i] + 1;
        //cout << Left <<  ' ' << Right << ' ';
        int L = 1, R = n, mn = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (r[mid] >= Left) {
                mn = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        L = 1, R = n;
        int mx = -1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (l[mid] <= Right) {
                mx = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        if (mx == mn) {
            ans += a[i] * (c[mx] != c[i]);
            continue;
        }
        if (mn + 1 < mx) {
            //write((__int128)(r[mx - 1] - l[mn + 1] + 1) + (__int128)cnt[c[i] - 'a'][mn] - (__int128)cnt[c[i] - 'a'][mx - 1]);
            //cout << endl;
            ans += (__int128)(r[mx - 1] - l[mn + 1] + 1) + (__int128)cnt[c[i] - 'a'][mn] - (__int128)cnt[c[i] - 'a'][mx - 1];
        }
        if (r[mn] != Left) {
            if (c[mn] != c[i]) {
                ans += (__int128)(r[mn] - Left);
            }
        }
        if (l[mx] != Right) {
            if (c[mx] != c[i]) {
                ans += (__int128)(Right - l[mx]);
            }
        }
       // write(ans);
        //cout << endl;
    }
    ans /= 2;
    write(ans);
}
void solve1() {
    scanf("%d", &n);
    long long mx = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %c",&a[i], &c[i]);
        mx = max(mx, a[i]);
    }
    if (n * mx <= 200005) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= a[i];j++) {
                s += c[i];
            }
        }
        int L = s.size();
        s = ' ' + s;
        int cnt = 0;
        for (int i = 1; i <= L; i++) {
            if (s[i] != s[L + 1 - i]) cnt++;
        }
        printf("%d", cnt / 2);
        return;
    }
    solve2();
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int t = 1;
    while (t--) {
        solve1();
    }
    return 0;
}
