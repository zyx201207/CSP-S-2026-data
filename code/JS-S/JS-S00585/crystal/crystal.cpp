#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int MAXN = 500005;
inline void fre(){
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    return ;
}
int n, m, ans = 0;
int a[MAXN];
bool s1 = true;
bool s2 = true;
inline int sp1(){
    int cnt = 1, num = 0;
    while (num + cnt <= m){
        num += cnt;
        cnt ++;
    }
    return cnt;
}
inline int sp2(int kl){
    int cnt = 1, num = 0;
    while (num + (cnt * kl) <= m){
        num += (cnt * kl);
        cnt ++;
    }
    return cnt;
}
inline bool cnd(int x, int y){
    return x < y;
}
signed main()
{
    fre();
    scanf ("%lld%lld%lld", &n, &m, &a[1]);
    if (a[1] != 1) s1 = false;
    for (rg int i = 2; i <= n; i++){
        scanf ("%lld", &a[i]);
        if (a[i] != i) s1 = false;
        if (s2){
            if (a[i] - a[i - 1] != a[2] - a[1]) s2 = false;
        }
    }
    if (s1){
        printf ("%lld\n", sp1());
        return 0;
    }
    if (s2){
        printf ("%lld\n", sp2(a[2] - a[1]));
        return 0;
    }
    sort (a + 1, a + n + 1, cnd);
    for (rg int k = 2; k <= n; k++){
        for (rg int i = 1; i <= n - k + 1; i++){
            int op = i + k - 1;
            int ks = 0;
            for (rg int j = i; j < i + k - 1; j++){
                ks += (a[op] - a[j]);
                if (ks > m) break;
            }
            if (ks <= m) ans = k;
        }
    }
    printf ("%lld\n", ans);
    return 0;
}/*#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
inline void fre(){
    freopen (".in", "r", stdin);
    freopen (".out", "w", stdout);
    return ;
}
signed main()
{

    return 0;
}*/
