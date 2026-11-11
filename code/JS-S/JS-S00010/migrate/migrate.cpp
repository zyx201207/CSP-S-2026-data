#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        ll n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll k=x[2]-x[1];
        ll g=d/k;
        ans=1ll*(n-2g-2)*(g-1)*2;
        ans=max(ans,(ll)0);
        cout<<ans<<"\n";
    }
    return 0;
}

