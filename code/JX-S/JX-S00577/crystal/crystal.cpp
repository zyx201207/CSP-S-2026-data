#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e18+5;
const int MAXN=5*1e5+5;
ll n,m;
ll a[MAXN],sum[MAXN];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    sum[0]=0;
    for (int i=1;i<=n;i++) {
        sum[i]=a[i]+sum[i-1];
    }
    ll l=1,r=n;
    while (l<r) {
        ll mid=(l+r+1)>>1,cnt=INF;
        for (int i=1;i+mid-1<=n;i++) {
            ll j=i+mid-1;
            ll res=a[j]*mid-(sum[j]-sum[i-1]);
            cnt=min(cnt,res);
        }
        if (cnt>m) {
            r=mid-1;
        }
        else {
            l=mid;
        }
    }
    cout<<l<<'\n';
    return 0;
}
