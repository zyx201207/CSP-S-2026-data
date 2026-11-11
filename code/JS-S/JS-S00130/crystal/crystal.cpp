#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define getchar getchar_unlocked

void read(int &x) {
    bool flag = 0; int res = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') flag = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    x = (flag?-res:res);
}

const int N = 5e5+5;
int a[N];
int s[N];
int n, m;
bool check(int mid) {
    for (int i = 1; i + mid - 1 <= n; i++) {
        int l = i, r = i + mid - 1;
        if (((r - l) * a[r] - s[r - 1] + s[l - 1]) <= m) return 1;
    }
    return 0;
}


signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    read(n), read(m);
    
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) 
        s[i] = s[i-1] + a[i];
    int l = 1, r = n;
    int mid = (l + r) >> 1;
    int ans = 0;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid;
    }
    printf("%lld", ans);
    

    return 0;
}