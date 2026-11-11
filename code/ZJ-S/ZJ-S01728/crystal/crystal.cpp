#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair <int,int>;
using LL = long long;
using ULL = unsigned long long;
template <typename T1,typename T2> void tomax (T1 &x,T2 y) {if (y > x) x = y;}
template <typename T1,typename T2> void tomin (T1 &x,T2 y) {if (y < x) x = y;}
const int N = 500010;
int n;
LL m;
LL a[N];
LL s[N];
void mian () {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort (a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for (int i = 1,j = 0;i <= n;i++) {
        while ((LL)(i - j) * a[i] - (s[i] - s[j]) > m) j++;
        tomax (ans,i - j);
    }
    cout << ans << endl;
}
int main () {
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    int T = 1;
    // cin >> T;
    while (T--) mian ();
    return 0;
}