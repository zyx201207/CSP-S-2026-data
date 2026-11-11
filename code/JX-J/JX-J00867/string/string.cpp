#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, tot, len[N];
char c[N];
void solve(){
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> len[i] >> c[i];
        tot += len[i];
    }
    bool ok = tot & 1;
    tot >>= 1;
    int i = 1, sum = 0;
    for(;;++i){
        sum += len[i];
        if(sum >= tot) break;
    }
    int lidx = i, ridx = i + 1;
    bool ok2 = ok;
    if(ok && len[i + 1] == 1) ++ridx, ok2 = 0;
    int ans = 0;
    int l = len[lidx] - sum + tot, r = len[ridx] + sum - tot;
    if(sum == tot) r += ok2;
    else l -= ok2;
    int lsum = l, rsum = r;
    for(;ridx <= n && lidx;){
        if(tot - lsum >= rsum - tot - ok){
            if(c[lidx] != c[ridx]) ans += len[ridx];
            rsum += len[++ridx];
        }else{
            if(c[lidx] != c[ridx]) ans += len[lidx];
            lsum += len[--lidx];
        }
    }
    cout << ans;
}

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
