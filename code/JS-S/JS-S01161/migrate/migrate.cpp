#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 6;
int n,l,a[N],ans,dis[305][305],fangan[305][305];
main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","r",stdin);
    int c,T;cin>>c>>T;
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    while(T--){
        memset(fangan,0,sizeof fangan);
        memset(dis,0,sizeof dis);
        ans=0;
        cin>>n>>l;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(abs(a[i]-a[j])<=l){
                    dis[i][j]=1;
                }else dis[i][j]=1e18;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(i==j||j==k||i==k) continue;
                    if(dis[j][k]>dis[j][i]+dis[i][k]) {
                        dis[j][k]=dis[j][i]+dis[i][k];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++){
                for(int k=j+1;k<=n;k++){
                    if(i==j||j==k||i==k) continue;
                    if(dis[j][k]==dis[j][i]+dis[i][k]){
                        fangan[j][k]++;
                    }
                }
            }
        }
           // if(T==13)
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                  //  cout<<fangan[i][j] << ' ';
                    if(fangan[i][j]==2) ans++;
                }
            }
        cout<<ans<<'\n';
    }
}
