#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll ans=0;
    for(int i=n;i>=1;i--){
        ll cur=m;
        for(int j=i;j>=1;j--){
            ll cost=a[i]-a[j];
            if(cost<=cur){
                cur-=cost;
                if(j==1){
                    ans=max(ans,i);
                }
            }
            else{
                ans=max(i-j,ans);break;
            }
        }
    }
    cout<<ans;
    return 0;
}
