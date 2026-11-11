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
const int N = 5e5 + 5;

int n , m , res;
int a[N] , s[N];

signed main ()
{
    freopen ("crystal.in" , "r" , stdin);
    freopen ("crystal.out" , "w" , stdout);
    n = read () , m = read ();
    fro (i , 1 , n) a[i] = read ();
    std :: sort (a + 1 , a + n + 1);
    fro (i , 1 , n) s[i] = s[i - 1] + a[i];
    fro (i , 1 , n)
    {
        int l = 1 , r = i , ans = i;
        while (l <= r)
        {
            int mid = l + r >> 1;
            int cnt = i - mid + 1;
            if (cnt * a[i] - (s[i] - s[mid - 1]) <= m) r = mid - 1 , ans = mid;
            else l = mid + 1;
        }
        int cnt = i - ans + 1;
        // if (cnt == 4236) cerr << cnt * a[i] - (s[i] - s[ans - 1]) << " " << m << "\n";
        chkmax (res , i - ans + 1);
    }
    std :: cout << res ;
    return 0;
}
