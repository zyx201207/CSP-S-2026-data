#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
long long c,T,n,a[N],f[305][305],d,g[305][305],vis[305][305];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        memset(g,0,sizeof g);
        memset(vis,0,sizeof vis);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                f[i][j]=2e5;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(abs(a[i]-a[j])<=d){
                    f[i][j]=1;
                    g[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j||j==k||k==i)continue;
                    if(f[i][j]>f[i][k]+f[k][j]){
                        f[i][j]=f[i][k]+f[k][j];
                        if(vis[i][k]||vis[j][k]||g[i][k]*g[j][k]>2){
                            vis[i][j]=1;
                        }else{
                            g[i][j]=g[i][k]*g[k][j];
                        }
                    }else if(f[i][j]==f[i][k]+f[k][j]){
                        if(vis[i][k]||vis[j][k]||g[i][j]+g[i][k]*g[j][k]>2){
                            vis[i][j]=1;
                        }else{
                            g[i][j]+=g[i][k]*g[k][j];
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                // cout<<f[i][j]<<"\n";
                if(!vis[i][j]&&g[i][j]==2&&f[i][j]<=n){
                    // cout<<"("<<i<<","<<j<<")"<<"\n";
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}