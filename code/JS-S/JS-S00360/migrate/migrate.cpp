#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int C,T,n,m,a[N],f[N][N],g[N][N],nxt[N][N],las[N][N],ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            nxt[i][1]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
            nxt[i][0]=i;
            if(nxt[i][1]==i){
                nxt[i][1]=0;
                continue;
            }
            f[i][i+1]++;
            f[i][nxt[i][1]+1]--;
        }
        for(int k=2;k<=n;k++)
            for(int i=1;i<=n;i++)
                nxt[i][k]=nxt[nxt[i][k-1]][1];
         for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                if(!nxt[i][k])continue;
               for(int j=nxt[i][k-1]+1;j<=nxt[i][k];j++){
                    g[i][j]+=g[i][j-1];
                    f[i][nxt[i][k]+1]+=g[i][j-1];
                    f[i][nxt[j][1]+1]-=g[i][j-1];
               }

            }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(g[i][j]==2)ans++;
        cout<<ans<<"\n";
    }
    return 0;
}
