#include <bits/stdc++.h>
#define int long long
#define gc getchar
const int N = 5e5 + 10;

using namespace std;
namespace Sol{

int rd(){
    char c = gc(); int re = 0, fl = 1;
    while(c < '0' || c > '9'){
        if(c == '-') fl = -1; c = gc();
    }
    while(c >= '0' && c <= '9')
        re = re * 10 + c - '0', c = gc();
    return re * fl;
}

int a[N];

void main(){
    #ifdef LOCAL
    freopen("crystal0.in", "r", stdin);
    // freopen("crystal.out", "w", stdout);
    #else
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = rd(), m = rd(), ans = 1, cm = m, tmp = 0;
    for(int i=1; i<=n; i++) a[i] = rd();
    sort(a+1, a+n+1);
    for(int i=1; i<n; i++) a[i] = a[i+1] - a[i];
    // cout << k << '\n';
    // for(int i=1; i<=k; i++) 
    //     cout << c[i].v << ' ' << c[i].l << '\n';
    for(int i=n, j=i-1; i && j; i--){
        if(i < n) cm += a[i] * (i-j), tmp -= a[i];
        while(j >= 1 && cm >= a[j]+tmp) tmp += a[j--], cm -= tmp;
        ans = max(ans, i-j);
    }
    cout << ans;
}

}signed main(){Sol::main();}