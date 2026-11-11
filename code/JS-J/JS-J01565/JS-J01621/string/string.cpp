#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i ++ )
#define DF(i, a, b) for (int i = (a); i >= (b); i -- )
inline void chkmin(int& a, int b) { if (a > b) a = b; }
inline void chkmax(int& a, int b) { if (a < b) a = b; }

const int N = 200010;

int a[N];
char ch[N];
int n;

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    F(i, 1, n) cin >> a[i] >> ch[i];
    int l = 1, reml = a[1], r = n, remr = a[n], res = 0;
    while (l < r)
    {
        if (reml < remr)
        {
            if (ch[l] != ch[r]) res += reml;
            remr -= reml;
            l ++ ;
            reml = a[l];
        }
        else
        {
            if (ch[l] != ch[r]) res += remr;
            reml -= remr;
            r -- ;
            remr = a[r];
        }
    }
    cout << res << "\n";
    return 0; 
}