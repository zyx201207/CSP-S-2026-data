// migrate
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
template<typename ...Args> void Debug(const Args&... arg){
    int d[] = {(cerr << arg << ' ',0)...};
    cerr << '\n';
}
#define dbg(...) Debug(#__VA_ARGS__,'=',__VA_ARGS__)
#else
#define dbg(...) void()
#endif // LOCOL
const int N = 2e6 + 5;
long long a[N];
void solve(int c){
    int n;
    long long d;
    cin >> n >> d;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (n == 1) return cout << "0\n",void();
    if (c == 11 || c == 12){
        long long diff = d / abs(a[2] - a[1]);
        if (diff > 1) cout << max(n - diff * 2 + 1,0ll) << '\n';
        else cout << "0\n";
    }
    cout << "0\n";
}
int main(){
#ifdef LOCAL

#else
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int c,t;
    cin >> c >> t;
    while (t--) solve(c);
    return 0;
}
/*
0 2
260000 86666
1 2
260000 2
1 2
*/
