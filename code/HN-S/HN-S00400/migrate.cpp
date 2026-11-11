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
const int N = 2e6 + 5;

int cid , T , ans ;
int n , d ;
int a[N] , R[N] , c[N] , cnt ;
std :: vector <int> e[N] ;
std :: vector <int> root ;

// #define ls (o << 1)
// #define rs (o << 1 | 1)

// struct Info
// {
//     int c0 , c1 , c2;
//     inline friend Info opeartor + (Info x , Info y)
//     {
//         Info res ;
//         res.c0 = x.c0 + y.c0;
//         res.c1 = x.c1 + y.c1;
//         res.c2 = x.c2 + y.c2;
//         return res;
//     }
// } f[N << 2];
// int v[N << 2];

// inline void push_up (int o)
// {
//     f[o] = f[ls] + f[rs];
// }
// inline void tag (int o , int w)
// {
//     if (w == 1) f[o].c2 += f[o].c1 , f[o].c1 += f[o].c0 , f[o].c0 = 0;
//     else if (w > 2) f[o].c2 += f[o].c1 + f[o].c0 , f[o].c1 = f[o].c0 = 0;
//     else if (w == -1) 
//     v[o] += w;
// }
// inline void change (int o , int l , int r)
// {
//     ;
// }
int dw = 0;
inline void add (int x , int w)
{
    if (c[x] == 1) cnt--;
    c[x] += w;
    if (c[x] == 1) cnt++;
}
std :: vector < std :: pair <int , int> > er;

inline void dfs (int u)
{
    // cerr << u << "\n";
    // fro (i , 1 , n) cerr << c[i] << " "; cerr << "\n";
    // fro (i , u + 1 , n) ans += (c[i] == 1);
    int now = er.size ();
    // if (now > 10000000) cerr << "nooo" , exit (0);
    ans += cnt;
    int lst = 0;
    for (auto v : e[u])
    {
        for (auto op : {1 , 2}) if (op > lst)
        {
            // dw++;
            int now1 = u , now2 = u - op;
            if (now2 <= v) continue;
            lst = op;
            while (R[now1] > now1)
            {
                if (R[now2] <= now1 || c[now2] > 2 || now1 - now2 > 2) { break;}
                // dw++;
                fro (i , now1 + 1 , R[now2]) add (i , 1);
                er.push_back ({now1 + 1 , R[now2]});
                now1 = R[now1] , now2 = R[now2];
            }
        }
        dfs (v);
    }
    // for (auto i : er) 
    while (er.size () != now)
    {
        auto i = er.back ();
        fro (j , i.first , i.second) add (j , -1);
        er.pop_back ();
    }
}

inline void FakeMain ()
{
    root.clear (); ans = 0; cnt = 0;
    fro (i , 1 , n) e[i].clear () , c[i] = 0;

    n = read () , d = read ();
    fro (i , 1 , n) a[i] = read ();
    fro (i , 1 , n)
    {
        R[i] = std :: upper_bound (a + 1 , a + n + 1 , a[i] + d) - a - 1;
        if (R[i] > i) e[R[i]].push_back (i);
        if (R[i] == i) root.push_back (i);
    }
    // fro (i , 1 , n) std :: sort (all (e[i]));
    for (auto i : root)
    {
        dfs (i);
        // cerr << "\n";
    }
    std :: cout << ans << "\n";
}

bool ed;
signed main ()
{
    freopen ("migrate.in" , "r" , stdin);
    freopen ("migrate.out" , "w" , stdout);
    for (cid = read () , T = read (); T -- ; FakeMain ());
    cerr << dw ;
    cerr << "\nMemory: " << std::fabs (&bg - &ed) / 1024. / 1024. << " Mib\n";
    return 0;
}
