#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500005],pre[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; i++){
        int l = -1,r = i;
        while (l + 1 < r){
            int mid = (l + r) / 2;
            if ((i - mid) * a[i] - (pre[i] - pre[mid]) <= m) r = mid;
            else l = mid;
        }
        ans = max(ans,i - r);
    }
    cout << ans;
    return 0;
}//简单题，比 club 简单
//怎么 ios 打成 os 了，还好最后十分钟检查出来了，我是区