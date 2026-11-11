#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int n,m;
int a[N],sum[N];
int ans = 0;
signed main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a + 1 , a + n + 1);
    for(int i = 1;i<=n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1;i<=n;i++){
        int l = 1,r = i,mid,res = 1;
        while(l <= r){
            mid = (l + r) >> 1;
            int len = (i - mid + 1);
            int s = a[i] * len;
            if(s - (sum[i] - sum[mid - 1]) <= m){
                r = mid - 1;
                res = len;
            }else{
                l = mid + 1;
            }
        }
        ans = max(ans , res);
    }
    cout<<ans<<"\n";
    return 0;
}
