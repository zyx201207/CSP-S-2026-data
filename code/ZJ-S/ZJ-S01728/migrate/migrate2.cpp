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
void mian () {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n >= 260000) return ;
    for (int i = 1,j = 1;i <= n;i++) {
        while (j + 1 <= n && a[j + 1] - a[i] <= m) j++;
        nxt[i] = j;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int j = nxt[i];
        int last = i;
        int cnt = 0;
        while (nxt[j] > j) {
            int tmp = cnt;
            int now = 0;
            for (int p = nxt[j],l = j - 1;p >= j + 1;p--) {
                // while (l > last && a[p] - a[l] <= m) now++,l--,cnt += p == nxt[j];
                for (int l = last + 1;l <= j + 1;l++) tmp += a
                tmp += now;
                if (i == 1) cout << p << ' ' << cnt << ' ' << tmp << "=======" << endl;
                if (tmp == 1) ans++,cout << i << ' ' << p << endl;
            }
            last = j;
            j = nxt[j];
        }
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