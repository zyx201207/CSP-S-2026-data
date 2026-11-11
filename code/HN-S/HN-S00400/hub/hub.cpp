#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(),v.end()
#define fro(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
inline void chkmin (int& x , int y) { (x > y) && (x = y); }
inline void chkmax (int& x , int y) { (x < y) && (x = y); }
bool bg;
namespace FastIO
{
    char buf[1 << 22] , *p1 = buf , *p2 = buf;
    #define FG() ((p1 == p2 && (p2 = ((p1 = buf) + fread (buf , 1 , 1 << 21 , stdin))\
     , p1 == p2)) ? EOF : *p1++)
    inline int read ()
    {
        int s = 0 , f = 1; char c = FG ();
        while (c < '0' || c > '9') { if (c == '-') f = -f; c = FG (); }
        while (c >= '0' && c <= '9') { s = s * 10 + (c - '0'); c = FG (); }
        return s * f;
    }
}; // WA on read INT_MIN
using FastIO :: read;
const int N = 1e6 + 5;

int cid , T , ans ;
int n , k ;
std :: vector <int> e[N] ;
int now ;
int f[N] ;
bool g[N] ;
struct edge { int u , v; } a[N];
int fa[N];
inline int Find (int x) { return x == fa[x] ? x : fa[x] = Find (fa[x]); }
inline void Union (int x , int y)
{
    x = Find (x) , y = Find (y);
    if (x == y) return ;
    fa[x] = y;
}
std::mt19937 rnd (time (0));
int dw ;
int ct ;
int S;

inline void dfs (int u , int fat)
{
    int tmp = 0;
    for (auto v : e[u])
    {
        if (v == fat) continue;
        dfs (v , u);
        chkmax (f[u] , f[v] + 1);
        // g[u] |= g[v];
        tmp += g[v];
    }
    if (S != -1) g[u] = (S >> u - 1 & 1);
    else 
    {
        if (f[u] > now || tmp > 1)
        {
            g[u] = 1;
            dw--;
        }
        else if (tmp && dw > 0 && !(rnd () % (dw + 1)))
            g[u] = 1 , dw--;
        else if (dw > 0 && ct == 2)
            g[u] = 1 , dw--;
        if (tmp && !g[u]) ct++;
    }

    if (g[u]) f[u] = 0;
}
inline bool check (int mid)
{
    S = -1;
    if (n <= 10)
    {
        fro (S , 0 , (1 << n) - 1)
    {
        ::S = S;
        now = mid; dw = k; ct = 0;
        fro (i , 1 , n) f[i] = g[i] = 0 , fa[i] = i;
        dfs (1 , 0);
        fro (i , 2 , n)
        {
            int u = a[i].u , v = a[i].v;
            if (g[u] && g[v]) Union (u , v);
        }
        int res = 0 , cnt = 0;
        fro (i , 1 , n)
        {
            if (fa[i] == i && g[i]) cnt++;
            res += g[i];
        }
        if (res <= k && cnt <= 2) return 1;
    }
        return 0;
    }
    fro (i , 1 , 100000 / n)
    {
        now = mid; dw = k; ct = 0;
        fro (i , 1 , n) f[i] = g[i] = 0 , fa[i] = i;
        dfs (1 , 0);
        fro (i , 2 , n)
        {
            int u = a[i].u , v = a[i].v;
            if (g[u] && g[v]) Union (u , v);
        }
        int res = 0 , cnt = 0;
        fro (i , 1 , n)
        {
            if (fa[i] == i && g[i]) cnt++;
            res += g[i];
        }
        if (res <= k && cnt <= 2) return 1;
    }
    return 0;
}

inline void FakeMain ()
{
    fro (i , 1 , n) e[i].clear ();
    n = read () , k = read ();
    fro (i , 2 , n)
    {
        int u = read () , v = read ();
        e[u].push_back (v) , e[v].push_back (u);
        a[i] = {u , v};
    }
    int l = 0 , r = n , ans = n;
    // cerr << check (1) << "\n";
    // return ;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check (mid)) ans = mid , r = mid - 1;
        else l = mid + 1;
    }
    std :: cout << ans << "\n";
}

bool ed;
signed main ()
{
    freopen ("hub.in" , "r" , stdin);
    freopen ("hub.out" , "w" , stdout);
    for (cid = read () , T = read (); T -- ; FakeMain ());
    cerr << "\nMemory: " << std::fabs (&bg - &ed) / 1024. / 1024. << " Mib\n";
    return 0;
}
