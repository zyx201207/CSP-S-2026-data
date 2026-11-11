#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n, a[N],m,sum[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i=1;i<=n;i++)
        sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n;i++){
        int l=1,r=i,best=1;
        while(l<=r){
            int mid = (l + r) / 2;
            int res1 = sum[i] - sum[mid - 1];
            int res2=a[i]*(i-mid+1);
            if(res2-res1<=m){
                r = mid - 1;
                best = mid;
            }else
                l = mid + 1;
        }
        ans = max(ans, i - best + 1);
    }
    cout << ans << '\n';
    return 0;
}