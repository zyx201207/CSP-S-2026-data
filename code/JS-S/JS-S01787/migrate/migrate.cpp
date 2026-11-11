#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,x[2000005],n,d,a[2000005];
bool vis[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ll ans=0;
        cin>>n>>d;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            cin>>x[i];
            vis[x[i]]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=x[i]+d+1;j<=x[i]+d+d-1;j++){
                if(!vis[j])continue;
                ll cnt=0,k=1;
                while(vis[j-k]&&k<=d)cnt++,k++;
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
