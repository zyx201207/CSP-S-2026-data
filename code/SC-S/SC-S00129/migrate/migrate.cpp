#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-(x)))
#define mkp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')
          f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
inline void write(ll x){
    if(x < 0){
        x = -x;
        putchar('-');
    }
    if(x > 9)
      write(x / 10);
    putchar(x % 10 + '0');
}
ll d, ans;
int c, T, n;
ll A[N];
int nxt[N], pre[N];
int a[N], b[N];
int vis[N];
inline int ask(int l, int r, int v){
    int num = 0;
    for(int i = r; i >= l; --i){
        if(nxt[i] < v || num > 1)
          break;
        ++num;
    }
    return num;
}
inline void get1(int l, int r, int v){
    for(int i = l; i <= r; ++i)
      a[i] += v;
}
inline void get2(int l, int r, int v){
    for(int i = l; i <= r; ++i)
      b[i] += v;
}
inline void solve(int l, int r){
    for(int i = l; i <= r; ++i)
      a[i] = 1, b[i] = 0;
    for(int i = l; i < r; i = nxt[i]){
        int mid = nxt[i];
        if(mid - i + 1 <= 2)
          continue;
        for(int x = i; x < mid; ++x){
            ans += b[x];
            if(nxt[x] == mid + 1){
                // ans += 1ll * a[x] * (nxt[mid] - nxt[mid - 1]);
                get2(nxt[mid - 1] + 1, nxt[mid], a[x]);
            }
            else{
                // ans += 1ll * a[x] * (nxt[mid - 1] - nxt[mid - 2]);
                // ans += 1ll * b[x] * (nxt[mid] - nxt[mid - 1]);
                get2(nxt[mid - 2] + 1, nxt[mid - 1], a[x]);
                get1(nxt[mid - 1] + 1, nxt[mid], b[x]);
            }
            // cerr << x << ' ' << ans << ' ' << a[x] << ' ' << b[x] << '\n';
        }       
    }
}
inline void solve(){
    ans = 0;
    n = read(), d = read();
    for(int i = 1; i <= n; ++i)
      A[i] = read();
    if(c == 11 || c == 12){
        ll x = A[2] - A[1];
        d /= x;
        // cerr << d << '\n';
        if(d <= 1)
          puts("0");
        else{
            write(max(0ll, n - (2 * d - 1)));
            putchar('\n');            
        }
        return ;
    }
    // if(n > 1000){
    //     puts("0");
    //     return ;
    // }
    for(int i = 1; i <= n; ++i){
        nxt[i] = max(nxt[i - 1], i);
        while(nxt[i] < n && A[nxt[i] + 1] - A[i] <= d)
          ++nxt[i];
        if(nxt[i - 1] == nxt[i])
          pre[i] = pre[i - 1] + 1;
        else
          pre[i] = 0;
        // cerr << i << ' ' << nxt[i] << '\n';
    }
    if(c == 13 || c == 14){
        int mid = nxt[1];
        if(mid <= 2){
            puts("0");
            return ;
        }
        for(int i = 1; i < mid; ++i){
            if(nxt[i] > mid + 1)
              break;
            if(nxt[i] == mid + 1)
              ans += n - nxt[mid - 1];
            else if(mid >= 2)
              ans += nxt[mid - 1] - nxt[mid - 2];
        }
        write(ans);
        putchar('\n');
        return ;
    }
    if(n <= 5000){
        int ans = 0;
        nxt[n] = n + 1;
        for(int u = 1; u <= n; ++u){
            for(int v = 1; v <= n; ++v)
            vis[v] = 0;
            ll sum = 0;
            int lst = n + 1;
            for(int p = u; ; p = nxt[p]){
                for(int v = p + 1; v <= nxt[p]; ++v){
                    if(v > n)
                    continue;
                    ll rsum = ask(lst + 1, p - 1, v);
                    if(sum + rsum == 1 && !(rsum == 1 && vis[p - 1] >= 1)){
                        // cerr << "w: " << u << ' ' << v << '\n';
                        // Ans.push_back({u, v});
                        ++ans;
                        vis[v] = 1;
                    }
                    else if(!sum && !rsum)
                    vis[v] = 0;
                    else
                    vis[v] = 2;
                    // cerr << v << ' ' << vis[v] << '\n';
                }
                sum += ask(lst + 1, p - 1, nxt[p]);
                lst = p;
                if(nxt[p] == p || nxt[p] > n || sum > 1)
                  break;            
            }
        }
        write(ans);
        putchar('\n');
        return ;   
    }
    // cerr << "Yes\n";
    int lst = 1;
    for(int i = 1; i <= n; ++i){
        if(nxt[i] == i){
            solve(lst, i);
            lst = i + 1;
        }
    }
    write(ans);
    putchar('\n');
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(), T = read();
    while(T--)
      solve();
    return 0;
}
/*
g++ migrate.cpp -o migrate -std=c++14 -O2 -Wall

./migrate < migrate1.in > migrate1.out
./migrate < migrate2.in > migrate2.out
./migrate < migrate3.in > migrate3.out
./migrate < migrate4.in > migrate4.out
./migrate < migrate5.in > migrate5.out
./migrate < migrate6.in > migrate6.out

diff migrate1.out migrate1.ans
diff migrate2.out migrate2.ans
diff migrate3.out migrate3.ans
diff migrate4.out migrate4.ans
diff migrate5.out migrate5.ans
diff migrate6.out migrate6.ans
*/