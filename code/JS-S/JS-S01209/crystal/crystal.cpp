#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],i,c[500005],qz[500005];
map<ll,ll> mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
 //   freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
 //   cout<<n<<' '<<m<<'\n';
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    qz[1]=0;
    qz[0]=0;
    for(i=1;i<n;i++){
        c[i]=a[i+1]-a[i];
        qz[i+1]=qz[i]+c[i]*i;
    }
    ll f=0;
    for(i=2;i<n;i++){
        if(c[i]!=c[i-1]){
            f=1;
            break;
        }
    }
    if(f==0){
        ll gc=c[1];
        ll ans=m/gc,da=1;
        for(i=1;i<=n;i++){
            if(ans>=i){
                ans-=i;
                da++;
            }
        }
        cout<<da<<'\n';
        return 0;
    }
    ll jis=0;
    ll ans=1;
    for(i=1;i<=n;i++){
            if(qz[i]==qz[i-1]){
                jis++;
            }else{
                ans=max(ans,jis);
                jis=1;
            }
     //   cout<<qz[i]<<' ';
    }
  //  cout<<'\n';
    ans=max(ans,jis);
    for(i=1;i<n-ans;i++){
        for(ll j=i+ans;j<=n;j++){
                ll jis=0;
            for(ll i1=i;i1<j;i1++){
                jis+=c[i1]*(i1-i+1);
                if(jis>m){
                    break;
                }
            }
            if(jis>m){
                break;
            }
            ans=j-i+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
