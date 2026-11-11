#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll s[N],a[N];
ll e[1005][1005];
ll v[1005][1005],t,c;
ll n,ans=0,d;
vector<ll> E[1005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(e,0x3f3f3f3f,sizeof e);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            E[i].clear();
            for(int j=1;j<i;j++){
                if(a[i]-a[j]<=d){
                    e[j][i]=1;
                    E[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(auto k:E[i]){
                    e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                    if(k>j)break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(auto k:E[i]){
                    if(e[i][j]==e[i][k]+e[k][j]){
                        v[i][j]++;
                    }
                    if(k>j)break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(v[i][j]==2){
                    ans++;
                }
            }
        }
        memset(v,0,sizeof v);
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
