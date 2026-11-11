#include <bits/stdc++.h>
using namespace std; bool _M_membg;
int n;
long long m, a[500010];
long long s[500010];
long long mx[20][500010];
long long mxv(int l, int r){
    int t = __lg(r - l + 1);
    return max(mx[t][l], mx[t][r - (1 << t) + 1]);
}
bool chk(int L){
    for (int l = 1, r = L; r <= n; ++l, ++r){
        long long nd = mxv(l, r) * (r - l + 1) - (s[r] - s[l - 1]);
        if (nd <= m)return 1;
    }
    return 0;
}
bool _M_memed; int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    double _M_use_mem = fabs(&_M_membg - &_M_memed) / 1024 / 1024;
    clog << _M_use_mem << "M" << endl;
    assert(_M_use_mem <= 128);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)s[i] = s[i - 1] + a[i];
    copy_n(a + 1, n, mx[0] + 1);
    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
    int rs = 0, L = 1, R = n;
    while (L <= R){
        int M = L + R >> 1;
        if (chk(M))L = M + 1, rs = M;
        else R = M - 1;
    }
    cout << rs << endl;
    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14 -static -O2 -pedantic
./crystal <crystal1.in >crystal.out
diff crystal.out crystal1.ans
./crystal <crystal2.in >crystal.out
diff crystal.out crystal2.ans
./crystal <crystal3.in >crystal.out
diff crystal.out crystal3.ans
./crystal <crystal4.in >crystal.out
diff crystal.out crystal4.ans
*/