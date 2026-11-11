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
const int M = 5e5 + 5 , N = 505;

int cid , n , m , d , q;
int w[M];
int f[N][N];
std :: vector <std :: pair <int , int> > pos[M];

bool ed;
signed main ()
{
    freopen ("subway.in" , "r" , stdin);
    freopen ("subway.out" , "w" , stdout);
    cid = read () , n = read () , m = read () , d = read () , q = read ();
    fro (i , 1 , m) w[i] = read ();
    fro (i , 1 , n)
    {
        int k = read ();
        while (k--)
        {
            int x = read () , t = read ();
            pos[x].push_back ({i , t});
        }
    }
    memset (f , 0x3f , sizeof f);
    fro (i , 1 , m)
    {
        for (auto j : pos[i]) for (auto k : pos[i])
        {
            if (k.first <= j.first) continue;
            f[j.first][k.first] = j.second + k.second;
            f[k.first][j.first] = j.second + k.second;
        }
    }
    fro (i , 1 , n) f[i][i] = 0;
    fro (k , 1 , n) fro (i , 1 , n) fro (j , 1 , n)
        if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
    while (q--)
    {
        int x = read () , y = read ();
        int ans = 0x3f3f3f3f3f3f3f3f;
        for (auto i : pos[x]) for (auto j : pos[y])
        {
            int u = i.first , v = j.first;
            chkmin (ans , f[u][v] + w[x] + w[y] + j.second + i.second);
        }
        std :: cout << ans << "\n";
    }
    cerr << "\nMemory: " << std::fabs (&bg - &ed) / 1024. / 1024. << " Mib\n";
    return 0;
}
