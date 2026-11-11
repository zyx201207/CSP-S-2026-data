#include<bits/stdc++.h>
using namespace std;

bool Mbe;

#define int long long
const int N=2e6+5;

int n,m;
int a[N];

void solve(){
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int u=1;u<=n;u++){
        for(int v=u+3;v<=n;v++){
            int cnt=0;
           if(a[v]-a[u]<=m) continue;
            bool flag=0;
            for(int i=u;i<v;i++) if(a[i+1]-a[i]>m){
                flag=1;
                break;
            }
            if(flag) continue;
            for(int i=u;i<=v;i++){
                for(int j=i+3;j<=v;j++){
                    if(a[j]-a[i]<=m) continue;
                    for(int l=i+1;l<=j;l++)
                        for(int r=l+1;r<=j;r++){
                            if(a[r]-a[i]<=m&&a[j]-a[l]<=m){
                                cnt++;
                            }
                        }
                }
            }
            
            if(cnt==1){
                // cout<<u<<" "<<v<<"\n";
                ans++;
            }
            // if(u==1&&v==4) cout<<cnt<<"\n";
        }
    }
    cout<<ans<<"\n";
    
    return;
}

bool Med;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }

    // cerr<<fabs(&Mbe-&Med)/1024.0/1024.0<<"MB\n";
    // cerr<<ceil(clock()*1000.0/CLOCKS_PER_SEC)<<"ms\n";

    return 0;
}