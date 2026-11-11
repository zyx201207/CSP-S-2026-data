#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define rep(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i<=(t2);i+=(t3))
#define per(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i>=(t2);i-=(t3))
#define pb push_back

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    i64 n,m;cin>>n>>m;
    vector<i64> a(n+1),s(n+1);
    rep(i,1,n,1) cin>>a[i];
    sort(a.begin()+1,a.end());
    rep(i,1,n,1) s[i]=s[i-1]+a[i];
    i64 ans=0;
    rep(i,1,n,1){
        i64 l=0,r=i;
        while(l+1<r){
            i64 mid=(l+r)/2;
            if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) r=mid;
            else l=mid;
        }
        ans=max(ans,i-l);
    }
    cout<<ans<<'\n';
    return 0;
}
