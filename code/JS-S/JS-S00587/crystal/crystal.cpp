#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll n,m,ans;
ll a[MAXN];
ll d[MAXN];
inline ll get(int j,int i){
    return d[i]-d[j]-1ll*(a[i]-a[j])*(j-1);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    d[1]=0;
    for(ll i=2;i<=n;i++)
        d[i]=d[i-1]+1ll*(a[i]-a[i-1])*(i-1);
    for(int i=1;i<=n;i++){
        //er fen!!!!!!!!!!!!
        ll l=1,r=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(get(mid,i)<=m)
                r=mid-1;
            else
                l=mid+1;
        }
        //cout<<i<<" "<<l<<" "<<r<<'\n';
        ans=max(ans,(ll)i-r);
    }cout<<ans<<'\n';
    return 0;
}
// g++ crystal.cpp -o crystal -std=c++14 -O2