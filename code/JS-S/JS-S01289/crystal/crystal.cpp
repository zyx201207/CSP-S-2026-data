#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int a[N],qzh[N];
inline bool check(int L,int R,int m) {
    int need=a[R]*(R-L+1)-(qzh[R]-qzh[L-1]);
    if(need>m) return false;
    return true;
}
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) qzh[i]=qzh[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;++i) {
        int val=a[i];
        int L=0,R=i,mid;
        while(L+1<R) {
            mid=(L+R) >> 1;
            if(check(mid,i,m)) R=mid;
            else L=mid;
        }
        ans=max(ans,i-R+1);
    }
    cout << ans;
    return 0;
}