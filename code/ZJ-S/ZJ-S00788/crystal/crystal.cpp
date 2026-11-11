#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+6;
int n;
ll m,a[N],s[N];
bool check(int mid,int pos)  {
    ll sum=s[pos]-s[mid-1];
    ll delta=a[pos]*(pos-mid+1)-sum;
    return delta<=m;
}
int find (int pos) {
    int l=1,r=pos;
    while (l<r) {
        int mid=((l+r)>>1);
        if (check(mid,pos)) r=mid; else l=mid+1; 
    }
    return l;
}
void Solve () {
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    s[0]=0;
    for (int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    int res=1;
    for (int r=1;r<=n;++r) res=max(res,r-find(r)+1);
    cout<<res<<"\n";
} 
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while (T--) Solve();
    return 0;
}
