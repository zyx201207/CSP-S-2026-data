#include <bits/stdc++.h>
using namespace std; bool _M_membg;
int c, t;
int n;
long long d, x[2000010];
int rt[2000010], lf[2000010];
namespace S1 {
    void sol1(){
        for (int i = 1; i <= n; ++i)clog << rt[i] << " "; clog << endl;
        for (int i = 1; i <= n; ++i)clog << lf[i] << " "; clog << endl;
        long long rs = 0;
        for (int x = 1; x <= n; ++x)
            for (int y = x + 1; y <= n; ++y){
                if (rt[y - 1] == y - 1)break;
                vector<int> pts;
                for (int u = x; u < y; u = rt[u])pts.emplace_back(u);
                pts.emplace_back(y);
                vector<int> pts2;
                for (int u = y; u > x; u = lf[u])pts2.emplace_back(u);
                pts2.emplace_back(x);
                reverse(pts2.begin(), pts2.end());
                assert(pts.size() == pts2.size());
                bool f = 1; int c = 0;
                for (int i = 0; i < pts.size(); ++i){
                    if (pts[i] != pts2[i]){
                        ++c;
                        f &= pts[i] == pts2[i] + 1;
                    }
                }
                if (c == 1 && f)++rs;
            }
        cout << rs << "\n";
    }
}
namespace S2 {
    void sol2(){
        long long rs = 0;
        for (int L = 1, R; L <= n; L = R + 1){
            R = L; while (rt[R] != R)R = rt[R];
            for (int i = L + 1; i < R - 1; ++i){ // core (i,i+1)
                int lp = lf[i + 1], rp = rt[i]; // lp -> i+1 -> rp, rp -> i -> lp
                if (lp >= i || rp <= i + 1)continue;
                int cl = 0;
                for (int x = lp; x < i; ++x){
                    if (rt[x] > i + 1)break;
                    ++cl;
                }
                if (lf[i] == lp && rt[lp] == i + 1){
                    for (int u = lp; u > L; u = lf[u]){
                        if (rt[lf[u]] != u)break;
                        for (int i = lf[u]; i < u; ++i)
                            if (rt[i] == u)++cl;
                    }
                }
                int cr = 0;
                for (int x = rp; x > i + 1; --x){
                    if (lf[x] < i)break;
                    ++cr;
                }
                if (rt[i + 1] == rp && lf[rp] == i){
                    for (int u = rp; u < R; u = rt[u]){
                        if (lf[rt[u]] != u)break;
                        for (int i = u + 1; i <= rt[u]; ++i)
                            if (lf[i] == u)++cr;
                    }
                }
                // clog << i << "," << i + 1 << ":" << cl << "*" << cr << endl;
                // clog << "[" << lp << "," << rp << "]]" << endl;
                rs += 1ll * cl * cr;
            }
        }
        cout << rs << "\n";
    }
}
namespace S3 {
    void sol3(){
        long long rs = 0;
        for (int L = 1, R; L <= n; L = R + 1){
            R = L; while (rt[R] != R)R = rt[R];
            for (int i = L + 1; i < R - 1; ++i){ // core (i,i+1)
                int lp = lf[i + 1], rp = rt[i]; // lp -> i+1 -> rp, rp -> i -> lp
                if (lp >= i || rp <= i + 1)continue;
                int cl = upper_bound(rt + lp, rt + i, i + 1) - rt - lp; // cnt rt[lp,i) <= i+1
                // int cl = 0;
                // for (int x = lp; x < i; ++x){
                //     if (rt[x] > i + 1)break;
                //     ++cl;
                // }

                if (lf[i] == lp && rt[lp] == i + 1){
                    for (int u = lp; u > L; u = lf[u]){
                        if (rt[lf[u]] != u)break;
                        cl += upper_bound(rt + lf[u], rt + u, u) - rt - lf[u]; // cnt rt[lf[u],u) == u

                        // for (int i = lf[u]; i < u; ++i)
                        //     if (rt[i] == u)++cl;
                    }
                }

                int cr = lf + rp + 1 - lower_bound(lf + i + 2, lf + rp + 1, i); // cnt lf[i+2,rp+1) >=i
                // int cr = 0;
                // for (int x = rp; x > i + 1; --x){
                //     if (lf[x] < i)break;
                //     ++cr;
                // }

                if (rt[i + 1] == rp && lf[rp] == i){
                    for (int u = rp; u < R; u = rt[u]){
                        if (lf[rt[u]] != u)break;
                        cr += lf + rt[u] + 1 - lower_bound(lf + u + 1, lf + rt[u] + 1, u); // cnt lf[u+1,rt[u]+1) == u

                        // for (int i = u + 1; i <= rt[u]; ++i)
                        //     if (lf[i] == u)++cr;
                    }
                }
                // clog << i << "," << i + 1 << ":" << cl << "*" << cr << endl;
                // clog << "[" << lp << "," << rp << "]]" << endl;
                rs += 1ll * cl * cr;
            }
        }
        cout << rs << "\n";
    }
}
namespace S4 {
    int sl[2000010], sr[2000010];
    void sol4(){
        long long rs = 0;
        for (int L = 1, R; L <= n; L = R + 1){
            R = L; while (rt[R] != R)R = rt[R];
            sl[L] = 0;
            for (int u = L + 1; u <= R; ++u){
                if (rt[lf[u]] != u)sl[u] = 0;
                else sl[u] = upper_bound(rt + lf[u], rt + u, u) - rt - lf[u] + sl[lf[u]];
            }
            sr[R] = 0;
            for (int u = R - 1; u >= L; --u){
                if (lf[rt[u]] != u)sr[u] = 0;
                else sr[u] = lf + rt[u] + 1 - lower_bound(lf + u + 1, lf + rt[u] + 1, u) + sr[rt[u]];
            }
            for (int i = L + 1; i < R - 1; ++i){
                int lp = lf[i + 1], rp = rt[i];
                if (lp >= i || rp <= i + 1)continue;
                int cl = upper_bound(rt + lp, rt + i, i + 1) - rt - lp;
                if (lf[i] == lp && rt[lp] == i + 1){
                    cl += sl[lp];
                    // for (int u = lp; u > L; u = lf[u]){
                    //     if (rt[lf[u]] != u)break;
                    //     cl += upper_bound(rt + lf[u], rt + u, u) - rt - lf[u];
                    // }
                }
                int cr = lf + rp + 1 - lower_bound(lf + i + 2, lf + rp + 1, i);
                if (rt[i + 1] == rp && lf[rp] == i){
                    cr += sr[rp];
                    // for (int u = rp; u < R; u = rt[u]){
                    //     if (lf[rt[u]] != u)break;
                    //     cr += lf + rt[u] + 1 - lower_bound(lf + u + 1, lf + rt[u] + 1, u);
                    // }
                }
                rs += 1ll * cl * cr;
            }
        }
        cout << rs << "\n";
    }
}
void work(){
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)cin >> x[i];
    for (int i = 1; i <= n; ++i)rt[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1, assert(rt[i] >= i);
    for (int i = 1; i <= n; ++i)lf[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x, assert(rt[i] >= i);
    // if (c <= 6)return S1::sol1();
    // S2::sol2();
    // S3::sol3();
    S4::sol4();
}
bool _M_memed; int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    double _M_use_mem = fabs(&_M_membg - &_M_memed) / 1024 / 1024;
    clog << _M_use_mem << "M" << endl;
    assert(_M_use_mem <= 256);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--)work();
    return 0;
}
/*
g++ migrate.cpp -o migrate -std=c++14 -O2 -static -pedantic
./migrate <migrate1.in >migrate.out
diff migrate.out migrate1.ans -w
./migrate <migrate2.in >migrate.out
diff migrate.out migrate2.ans -w
./migrate <migrate3.in >migrate.out
diff migrate.out migrate3.ans -w
./migrate <migrate4.in >migrate.out
diff migrate.out migrate4.ans -w
./migrate <migrate5.in >migrate.out
diff migrate.out migrate5.ans -w
./migrate <migrate6.in >migrate.out
diff migrate.out migrate6.ans -w

./migrate <.in >.out
diff .out .ans -w
*/