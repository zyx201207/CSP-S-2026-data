#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005];
bool f[2000005];
bool e[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
            f[i]=0;
            e[i]=0;
        }
        for(int i=0;i<n-3;i++){
            if(a[i+2]-a[i]<=d && a[i+3]-a[i+1]<=d && a[i+3]-a[i]>d){
                f[i]=1;
                e[i+3]=1;
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            bool ppp=0;
            if(f[i])ppp=1;
            int sum=0;
            for(int j=i+1;j<n;j++){
                if(sum==2)break;
                if(a[j]-a[j-1]>d)break;
                if(f[j])ppp=1;
                if(ppp && e[j]){
                    ppp=0;
                    sum++;
                }
                if(sum==1){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
