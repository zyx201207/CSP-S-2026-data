#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],sum[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++){
        ll l=1,r=i;
        while(l<r){
            ll mid=(l+r)/2;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,(i-l+1));
    }
    cout<<ans;
    return 0;
}
