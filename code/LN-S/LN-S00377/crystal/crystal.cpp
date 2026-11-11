#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn=5e5+5;
ll n,m;
ll ans;
ll a[mxn],c[mxn];
bool cmp(ll x,ll y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    stable_sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
    for(int l=1,r=1;r<=n;r++){
        ll len=r-l+1;
        while(c[r]-c[l-1]+m<len*a[r]){
            //cout<<c[r]-c[l-1]<<" ";
            l++;
            len=r-l+1;
        }
        //cout<<"\n";
        ans=max(ans,len);
    }
    cout<<ans<<"\n";
    return 0;
}