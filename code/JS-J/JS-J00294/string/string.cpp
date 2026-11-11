#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    ll l=1,r=n;
    ll ald=0;
    ll ans=0;
    while(l<r){
        ll minn=min(a[l],a[r]);
        ald+=minn;
        if(c[l]!=c[r])ans+=minn;
        if(a[l]>a[r]){
            a[l]-=minn;
            r--;
        }
        else if(a[l]<a[r]){
            a[r]-=minn;
            l++;
        }
        else{
            r--;l++;
            ald+=minn;
        }
    }
    cout<<ans;
    return 0;
}
