#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],pre[N],sum[N];
ll l,r,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++){
        a[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n-1;i++){
        pre[i]=pre[i-1]+i*a[i];
        sum[i]=sum[i-1]+a[i];
    }
    l=1,r=1;
    while(l<=n-1&&r<=n-1){
        //cout<<l<<" "<<r<<"\n";
        if(r<l){
            r++;
            continue;
        }
        ll res=pre[r]-pre[l-1]-(l-1)*(sum[r]-sum[l-1]);
        if(res<=m){
            ans=max(r-l+2,ans);
            r++;
        }
        else{
            l++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
