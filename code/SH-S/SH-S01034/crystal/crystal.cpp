#include <bits/stdc++.h>
using namespace std;
int n,l,r,mid;
long long m,a[500010],b[500010];
inline bool check(int x) {
    for (int i=x;i<=n;++i) if (a[i]*x<=b[i]-b[i-x]+m) return true;
    return false;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) b[i]=b[i-1]+a[i];
    l=1;
    r=n+1;
    while (r-l>1) {
        mid=l+r>>1;
        if (check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}