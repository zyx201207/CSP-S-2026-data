#include <iostream>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N] = {};
int f[N] = {};
char c[N] = {};
int n = 0;
//int ans = 0;
int range(int sa, int ea, int sb, int eb) {
    if (sa <= sb && eb <= ea)
        return eb - sb + 1;
    if (sa >= sb && ea <= eb)
        return ea - sa + 1;
    if (sa <= sb && ea <= eb)
        return ea - sb + 1;
    if (sa >= sb && eb <= ea)
        return eb - sa + 1;
    return 0;
}
int solve() {
    int i = 1;
    int j = n;
    int res = 0;
    while (i < j) {
        int sa = f[i - 1] + 1;
        int ea = f[i];
        int sb = f[n] - f[j] + 1;
        int eb = f[n] - f[j - 1];        
        if (c[i] != c[j])
            res += range(sa, ea, sb, eb);
        if (ea == eb) {
            ++i;
            --j;
        } else if (ea < eb)
            ++i;
        else
            --j;
    }
    return res;
}
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(nullptr);
    cin >> n;
    int len = 0;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        f[i] = f[i - 1] + a[i];
    }/*
    int i = 1;
    int j = f[n];
    int idx1 = 1;
    int idx2 = n;
    while (i <= j) {
//        printf("i=%lld j=%lld idx1=%lld idx2=%lld f[idx1]=%lld f[idx2]=%lld c[idx1]=%c c[idx2]=%c\n", 
//            i, j, idx1, idx2, f[idx1], f[idx2], c[idx1], c[idx2]);
        if (c[idx1] != c[idx2])
            ++ans;
        ++i;
        --j;
        if (f[idx1] < i)
            ++idx1;
        if (f[idx2 - 1] == j)
            --idx2;
    }*/
//    cout << ans << end;
    cout << solve() << endl;
    return 0;
}