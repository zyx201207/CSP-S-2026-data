#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll a[500010],s[500010];
    ll n,m,ans=0,num;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<i;j++){
            num=s[i]-s[j-1];
            if(num+m>=a[i]*(i-j+1)){
                ans=max(ans,i-j+1);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
