#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],s[500005];
bool check(int k) {
    for(int i=k;i<=n;i++) {
        if(a[i]*k-(s[i]-s[i-k])<=m) return true;
    }
    return false;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n,mid;
    while(l<r) {
        mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}