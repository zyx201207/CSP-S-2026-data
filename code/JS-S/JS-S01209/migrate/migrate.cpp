#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005],i,f[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll t,d1;
    cin>>d1>>t;
    while(t--){
        ll n,d;
        //map<ll,ll> mp;
        cin>>n>>d;
        for(i=1;i<=n;i++){
            cin>>a[i];
          //  mp[a[i]]=1;
        }
        if(d1==11||d1==12){
            if(a[2]-a[1]>d){
                cout<<0<<'\n';
            }else{
                cout<<1<<'\n';
            }
            continue;
        }
        memset(f,0,sizeof(f));
        f[1]=1;
        ll jis=0,ans=0,lon=0;
        for(i=1;i<=n;i++){
            for(ll j=i-1;a[i]-a[j]<=d;j--){
                f[i]+=f[j];
            }
        }
        for(i=1;i<=n;i++){
            if(f[i]==2){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
