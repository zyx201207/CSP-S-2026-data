#include <bits/stdc++.h>
#define il inline
#define rg register
#define int ll
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
namespace XXI{
    const int maxn = 5e5+50;
    const char endl = '\n';
    int n,m;
    int a[maxn];
    int sum[maxn];
    //Think Twice,Code Once
    //Calm Down!
    il bool check(int l,int r,int x){
        return x*(r-l+1)-(sum[r]-sum[l-1])<=m;
    }
    int ans = 0;
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        cin >> n >> m;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        sort(a+1,a+1+n);
        for(int i = 1;i<=n;i++){
            sum[i] = sum[i-1]+a[i];
        }
        for(int i = 1;i<=n;i++){
            int l = 1,r = i;
            int res = i;
            while(l<=r){
                int mid = (l+r)>>1;
                if(check(mid,i,a[i])){
                    res = mid;
                    r = mid-1;
                } else l = mid+1;
            }
            ans = max(ans,i-res+1);
        }
        cout << ans << endl;
        return 0;
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    XXI::main();
    return 0;
}
