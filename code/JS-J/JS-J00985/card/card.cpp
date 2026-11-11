// Nina Iseri i love you

#include <bits/stdc++.h>
using namespace std;


#define range(v, l, r) next(begin(v), l), next(begin(v), r+1)
#define range_full(v) begin(v), end(v)

int64_t n, m;
int64_t fbc;
bool flagA{1}, flagB{1};
array<int64_t, size_t(5e5+5)> a;
array<int64_t, size_t(5e5+5)> c;
array<int64_t, size_t(5e5+5)> app;
array<int64_t, size_t(3e5+5)> p;
array<int64_t, size_t(3e5+5)> r;
vector<int64_t> v;

int32_t main() {
    ignore = freopen("card.in", "r", stdin);
    ignore = freopen("card.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int64_t i=1; i<=n; i++) {
        cin >> a[i];
        flagA &= (a[i]>=a[i-1]);
        fbc += (a[i]!=a[i-1]);
    }
    flagB = fbc<=4999;
    if (flagA) {
        // cout << "entered A\n";
        int64_t last{0};
        for (int64_t i=1; i<=n; i++) {
            if (a[i] != last) {
                last = a[i];
                r[a[i]] += i-1;
            }
            r[a[i]] ++;
        }
    }
    else if (flagB) {
        // cout << "entered B\n";
        for (int64_t i=n; i>=1; i--) {
            if (app[a[i]] == 0) {
                app[a[i]] = 1;
            }
            else {
                app[a[i]] = 2;
            }
        }
        int64_t lappidx{};
        int64_t last{0};
        for (int64_t i=1; i<=n; i++) {
            if (a[i] != last) {
                last = a[i];
                int64_t ll{v.size()};
                do {
                    --ll;
                } while (ll >=0 && a[v[ll]] == a[i]);
                if (ll == 0) {
                    r[a[i]] += i-1;
                }
                else {
                    r[a[i]] += i-a[v[ll]]-1;
                }
            }
            if (app[a[i]] == 2 && (a[v.back()]!=a[i] || v.back()+1 < i)) {
                v.push_back(i);
            }
            r[a[i]]++;
        }
    }
    else {
        for (int64_t i=1; i<=n; i++) {
            fill(range_full(p), 0);
            fill(range_full(c), 0);
            int64_t idx=1;

            for (int64_t j=i; j<=n; j++) {
                if (p[a[j]] != 0) {
                    for (int64_t k=p[a[j]]+1; k<idx; k++) {
                        p[c[k]] = 0;
                    }
                    idx = p[a[j]]+1;
                }
                else {
                    c[idx] = a[j];
                    p[a[j]] = idx;
                    idx++;
                }
            }
            for (int64_t i=1; i<idx; i++) {
                // cout << c[i] << " ";
                r[c[i]]++;
            }
            // cout << "\n";
        }
    }
    for (int64_t i=1; i<=m; i++) {
        cout << r[i] << " " ;
    }

    return 0;
}