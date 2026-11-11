#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll a[N],sum[N];
ll m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1;
    int ans=0;
    for(int k=1;k<=n;k++){//k target
        ll cnt=(k-l)*a[k]-(sum[k-1]-sum[l-1]);
        while(cnt>m&&l<k){
            cnt-=a[k]-a[l];
            l++;
        }
        if(cnt<=m)ans=max(ans,k-l+1);
        //cout<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}
