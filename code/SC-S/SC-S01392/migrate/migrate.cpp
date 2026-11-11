#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int inf=1e9;
int c,t,n;
long long d;
int f[N];
long long g[N],a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long ans=0;
        if(c>=11&&c<=12){
            if(d/(a[2]-a[1])<=1LL)cout<<0<<'\n';
            else cout<<max(0LL,1LL*n-(d/(a[2]-a[1]))-(d/(a[2]-a[1]))+1)<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)f[j]=inf,g[j]=0;
            f[i]=0;g[i]=1;
            for(int j=i+1;j<=n;j++){
                for(int k=i;k<j;k++){
                    // cout<<i<<' '<<j<<' '<<k<<' '<<f[j]<<' '<<f[k]<<' '<<g[j]<<' '<<g[k]<<'\n';
                    if(abs(a[j]-a[k])<=d){
                        if(f[k]+1<f[j]){
                            f[j]=f[k]+1;
                            g[j]=g[k];
                        }
                        else if(f[k]+1==f[j])g[j]+=g[k];
                    }
                }
                if(g[j]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
}