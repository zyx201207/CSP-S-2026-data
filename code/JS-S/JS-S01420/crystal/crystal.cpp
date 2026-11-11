#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,ans=1,t=0;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        while(t<i-1){
            if(sum[i]-sum[t]+m>=1ll*(i-t)*a[i]){
                ans=max(ans,i-t);
                break;
            }
            t++;
        }
    }
    cout<<ans;
    return 0;
}
//crystal 14:58
