#include<bits/stdc++.h>
#define int long long
#define inf 1073741823
#define llinf 4611686018427387903
using namespace std;

const int mod = 998244353;
const int D[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

int c, T = 1;

int read(){
    int n = 0, f = 1;
    char c = getchar();
    for(;c < '0' || c > '9'; c = getchar())
        if(c == '-')
            f = -1;
    for(;c >= '0' && c <= '9'; c = getchar())
        n = n * 10 + c - '0';
    return n * f;
}

int read(int& n){
    return n = read();
}

inline void write(int* a, int n){
    for(int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    puts("");
}

int n, d, a[2000010];
int r[2000010], l[2000010];

inline void solveA(){
    int dd = a[2] - a[1];
    if(dd * 2 > d){
        puts("0");
        return;
    }
    printf("%lld\n", max(0ll, n - d / dd * 2 + 1));
}

inline void solveB(){
    int p = 0;
    for(int i = 1; i <= n; i++)
        if(l[i] == 1 && r[i] == n)
            p = i;
    int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
    for(int i = 1; i < p - 1; i++)
        if(r[i] == p)
            l1++;
        else if(r[i] == p + 1)
            l2++;
    for(int i = p + 2; i <= n; i++)
        if(l[i] == p)
            r1++;
        else if(l[i] == p - 1)
            r2++;
    if(r[p - 1] == p + 1)
        l2++;
    if(l[p + 1] == p - 1)
        r1++;
    int ans = l1 * r2 + l2 * r1;
    printf("%lld\n", ans);
}

void solve(){
    read(n), read(d);
    for(int i = 1; i <= n; i++)
        read(a[i]);
    if(c == 11 || c == 12){
        solveA();
        return;
    }
    for(int i = 1, it = 1; i <= n; i++){
        for(;it < n;){
            if(a[it + 1] - a[i] <= d)
                it++;
            else
                break;
        }
        r[i] = it;
    }
    for(int i = n, it = n; i >= 1; i--){
        for(;it > 1;){
            if(a[i] - a[it - 1] <= d)
                it--;
            else
                break;
        }
        l[i] = it;
    }
    if(c == 13 || c == 14){
        solveB();
        return;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            vector<int> l, r;
            l.clear(), r.clear();
            for(int p = i;;){
                // printf("%lld\n", p);
                l.push_back(min(p, j));
                if(p >= j || p == ::r[p])
                    break;
                p = ::r[p];
            }
            for(int p = j;;){
                // printf("%lld\n", p);
                r.push_back(max(p, i));
                if(p <= i || p == ::l[p])
                    break;
                p = ::l[p];
            }
            reverse(r.begin(), r.end());
            // printf("(%lld, %lld)\n", i, j);
            // for(auto x : l)
            //     printf("%lld ", x);
            // puts("");
            // for(auto x : r)
            //     printf("%lld ", x);
            // puts("");
            if(l.size() != r.size() || l.empty())
                continue;
            int m = l.size(), cnt1 = 0, cnt2 = 0;
            if(l[0] != r[0] || l[m - 1] != r[m - 1])
                continue;
            for(int i = 0; i < m; i++)
                if(l[i] != r[i])
                    cnt1++, cnt2 = max(cnt2, abs(r[i] - l[i]));
            if(cnt1 == 1 && cnt2 == 1){
                ans++;//, printf("%lld, %lld\n", i, j);
            }
        }
    }
    printf("%lld\n", ans);
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    read(c), read(T);
    for(;T--;)
        solve();
}
