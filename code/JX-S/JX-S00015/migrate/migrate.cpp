#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll n,t,d,c,x[N],vis[N];
ll cont(ll u){
    ll sum=0;
    for(int i=u-1;i>=1;i--){
        if(x[u]-x[i]<=d){
            sum++;
        }else{
            break;
        }
    }return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll ans=0,last=cont(3);
        for(int i=4;i<=n;i++){
            ll s=cont(i);
            if(s<=last&&s==2){
                ans++;
                vis[i]++;
            }
            last=s;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
