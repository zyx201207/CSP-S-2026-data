#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans=-1ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    for(ll i=1;i<=n;i++){
        ll m1=m,p=1;
        for(ll j=i+1;j<=n;j++){
            ll l=a[i]-a[j];
            if(m1>=l){
                m1-=l;
                p++;
            }
            else{
                break;
            }
        }
        ans=max(ans,p);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
