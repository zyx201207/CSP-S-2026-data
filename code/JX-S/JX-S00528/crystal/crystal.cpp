#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long m;
long long a[maxn];
long long c[maxn];
inline bool check (int x) {
    long long f=0,sum=0;
    for(int i=x;i>=2;--i) {
        sum+=c[i];
        f+=sum;
    }
    if(f<=m) return true;
    for(int l=2,r=x+1;r<=n;++l,++r) {
        f-=sum;
        f+=(x-1)*c[r];
        sum=sum-c[l]+c[r];
        if(f<=m) return true;
    }
    return false;
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;++i) c[i]=a[i]-a[i-1];
    int l=1,r=n;
    while(l<r) {
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}
