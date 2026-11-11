// crystal
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
const int N = 5e5 + 5;
long long a[N],sum[N];
long long get(int l,int r){
    return sum[r] - sum[l - 1];
}
int main(){
#ifdef LOCAL

#else
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 0;i < n;i++) sum[i + 1] = sum[i] + a[i + 1];
    int ans = 0;
    for (int i = 1;i <= n;i++){
        int l = 1,r = i,res = -1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (get(mid,i) + m >= a[i] * (i - mid + 1)) r = mid - 1,res = mid;
            else l = mid + 1;
        }
        if (~res) ans = max(ans,i - res + 1);
    }
    cout << ans << '\n';
    return 0;
}
