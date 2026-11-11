#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair <int,int>;
using LL = long long;
using ULL = unsigned long long;
template <typename T1,typename T2> void tomax (T1 &x,T2 y) {if (y > x) x = y;}
template <typename T1,typename T2> void tomin (T1 &x,T2 y) {if (y < x) x = y;}
#define endl '\n'
int tid;
const int N = 2000010;
int n;
LL m;
LL a[N];
int nxt[N];
LL f[N][2];
void mian () {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1,j = 1;i <= n;i++) {
        while (j + 1 <= n && a[j + 1] - a[i] <= m) j++;
        nxt[i] = j;
    }
    LL ans = 0;
    int i1,i2,i3,i4;
    for (i1 = 1;i1 <= n;i1++) {
        i2 = nxt[i1];
        i3 = nxt[i2];
        i4 = nxt[i3];
        if (i1 == i2 || i2 == i3) continue;
        LL l = -2e18;
        if (i2 - 2 > i1) tomax (l,a[i2 - 2] + m);
    }
    cout << ans << endl;
}
int main () {
    // freopen ("migrate4.in","r",stdin);
    // freopen ("migrate.out","w",stdout);
    ios :: sync_with_stdio (false),cin.tie (0),cout.tie (0);
    int T = 1;
    cin >> tid >> T;
    while (T--) mian ();
    return 0;
}