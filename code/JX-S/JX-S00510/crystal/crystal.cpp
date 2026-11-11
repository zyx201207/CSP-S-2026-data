#include <bits/stdc++.h>

using namespace std;

#define int long long // sikaoyifan...
#define endl '\n'
#define gc getchar
#define PII pair<int, int> 

int read() {
    int x = 0, f = 1;
    char c = gc();
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = gc();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = gc();
    }
    return x * f;
}

const int N = 500010, INF = 1e18;

int n, m;
int tmp[N];
int b[N], s[N], s2[N];
vector<int> a;
int mn, mx;

int find(int x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

unordered_map<int, int> cnt;
int res;

void pout(int u) {
    printf("u is %lld\n", u);
    for (int i = 1; i <= n; i ++ )
       printf("%lld ", a[i]);
    puts("");
}

void dfs(int u) {
    if (u > m) return;
    for (int i = 1; i <= n; i ++ ) cnt[a[i]] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        cnt[a[i]] ++;
        ans = max(ans, cnt[a[i]]);
    }

    res = max(res, ans);
    //pout(u);
    for (int i = 1; i <= n; i ++ ){
        a[i] ++;
        dfs(u + 1);
        a[i] --;
    }
}

void solve() {
    a.push_back(-INF);
    for (int i = 1; i <= n; i ++ ) {
        int x = read();
        a.push_back(x);
    }
    dfs(0);
    printf("%lld\n", res);
}

bool A, B;

void solve2() {
    int sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        sum += i;
        if (sum <= m) res = i + 1;
    }
    printf("%lld\n", res);
}

int kkk;

void solve3 () {
    int sum = 0;
    for (int i = 1; i <= n; i ++ ) {
        sum += i;
        if (kkk * sum <= m) res = i + 1;
    }
    printf("%lld\n", res);
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    n = read(), m = read();
    if (n <= 5 && m <= 10) {
        solve();
        return 0;
    }

    a.push_back(-INF);
    for (int i = 1; i <= n; i ++ ) {
        tmp[i] = read();
        a.push_back(tmp[i]);
        mx = max(mx, tmp[i]);
    }
    for (int i = 1; i <= n; i ++ )
        if (tmp[i] != i) A = true;
    if (!A) {
        solve2();
        return 0;
    }

    kkk = tmp[2] - tmp[1];
    for (int i = 2; i <= n; i ++ )
        if (tmp[i] - tmp[i - 1] != kkk) B = true;
    if (!B) {
        solve3();
        return 0;
    }
    int ans = 0;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 1; i <= n; i ++ ) {
        cnt[find(tmp[i])] ++;
        ans += (mx - tmp[i]);
    }

    // very big
    if (m >= ans) {
        printf("%lld\n", n);
        return 0;
    }

    // very small
    mn = n, mx = 1;
    for (int i = 1; i < a.size(); i ++ )
        mn = min(mn, cnt[i]), mx = max(mx, cnt[i]);
    if (m <= mn) {
        printf("%lld\n", mx);
        return 0;
    }
    
    // others
    n = a.size() - 1;
    for (int i = 1; i <= n; i ++ ) {
        if (i < n) b[i] = a[i + 1] - a[i];
        if (i < n) s[i] = s[i - 1] + b[i];
        s2[i] = s2[i - 1] + cnt[i];
    }

    int res = mx;
    for (int len = 1; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n; l ++ ) {
            int r = l + len - 1, sum = 0;

            for (int i = l; i < r; i ++ ) 
                sum += cnt[i] * (s[r - 1] - s[i - 1]);
            if (sum <= m) {
                res = max(res, s2[r] - s2[l - 1]);
            }
        }
    
    printf("%lld\n", res);
    //printf("%lld %lld %lld\n", L, R, ans);
    //cerr << "time use: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    return 0; 
}