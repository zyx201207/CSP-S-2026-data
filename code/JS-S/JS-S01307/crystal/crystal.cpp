#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,ans,a[500005];
void check(ll x){
    ll num=0,id=0;
    for (int j=x-1;j>=1;j--){
        num+=a[x]-a[j];
        if (num>m){
            id=j;
            break;
        }
    }
    if (id!=0) ans=max(ans,x-id);
    else ans=max(ans,x);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++){
        check(i);
    }
    cout<<ans;
    return 0;
}
