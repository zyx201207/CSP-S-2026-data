#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+5;

ll n,m;
ll a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&m<0) m+=a[i]-a[j++];
        ans=max(ans,i-j+1ll);
        m-=(i-j+1)*(a[i+1]-a[i]);
    }
    cout<<ans;
    return 0;
}