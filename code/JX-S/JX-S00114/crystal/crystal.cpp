#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int n,m,sum[N],anss;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++){
        int l = 1,r = i - 1,ans = i;
        while(l <= r){
            int mid = (l + r) >> 1;
            if ((i - 1 - mid + 1)*a[i] - (sum[i - 1] - sum[mid - 1]) <= m) ans = mid,r = mid - 1;
            else l = mid + 1;
        }
         anss = max(anss,i - ans + 1);
    }
    cout << anss << '\n';
    return 0;
}