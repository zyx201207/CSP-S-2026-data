#include<bits/stdc++.h>
using namespace std;
const int N=23170;
int c,t;
int g[N][N];
void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(g,0,sizeof(g));
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u][v]=1;
            g[v][u]=1;
        }
        floyd(n);
        int ans=0x3f3f3f3f;
        for(int i=0;i<=(1<<n);i++){
            int cnt=0;
            for(int j=0;j<=n;j++){
                if(i>>j&1){
                    cnt++;
                }
            }
            int bj=0;
            if(cnt==k){
                for(int j=0;j<=n;j++){
                    if(i>>j&1){
                        for(int k=0;k<=n;k++){
                            bj=max(bj,g[j][k]);
                        }
                    }
                }
                ans=min(ans,bj);
            }
        }
        cout<<ans+1<<"\n";
    }
    return 0;
}
