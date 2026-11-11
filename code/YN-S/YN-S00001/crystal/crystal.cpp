// [100,100]
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N];
__int128 pre[N];
bool check(int x){
    for(int l = 1;l <= n - x + 1;l++){
        int r = l + x - 1;
        __int128 t = (r - l) * a[r] - (pre[r - 1] - pre[l - 1]);
        if(t <= m) return 1;
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
    int l = 1,r = n,ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1;
    while(T--) solve();
    return 0;
}