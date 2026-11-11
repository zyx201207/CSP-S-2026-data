#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+5;
ll ch,t,n,d;
ll a[N];
ll pre[N];
ll c[N];
ll ans;
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ch>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(ll i=0;i<n;i++)
            cin>>a[i];
        c[0]=0;
        for(ll i=1;i<n;i++){
             c[i]=a[i]-a[i-1];
        }

        pre[0]=c[0];
        for(ll i=1;i<n;i++)
            pre[i]=pre[i-1]+c[i];

        for(ll i=0;i<n;i++){
            for(ll j=i+2;j<n;j++){
                if(c[i]>d||c[j]>d) continue;
                if((pre[j]-pre[i]+1)%d==0&&(pre[j]-pre[i]+1)/d==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
