#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q,w[20005],k[20005],a[505][20005],t[505][20005];
int b[20005][20005],Vis[20005],Dis[20005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(b,-1,sizeof(b));
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
        }
        for(int j=1;j<=k[i];j++){
            for(int h=1;h<=k[i];h++){
                int q=a[i][j],p=a[i][h];
                if(j==h) continue;
                if(b[q][p]!=-1){
                    b[q][p]=min(b[q][p],t[i][q]+t[i][p]);
                }
                else b[q][p]=t[i][q]+t[i][p];
                b[p][q]=b[q][p];
            }
        }
    }
    for(int i=1;i<=q;i++){
        memset(Dis,-1,sizeof(Dis));
        memset(Vis,0,sizeof(Vis));
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        Dis[x]=0;Vis[x]=0;
        for(int i=1;i<m;i++){
            int pos=0,sum=0x3f3f3f3f;
            for(int j=1;j<=m;j++){
                if(Vis[j]==0&&Dis[j]<sum&&Dis[j]!=-1){
                    sum=Dis[j];pos=j;
                }
            }
            Vis[pos]=1;
            for(int j=1;j<=m;j++){
                if(j==pos) continue;
                if((Dis[j]>Dis[pos]+b[pos][j]||Dis[j]==-1)&&b[pos][j]!=-1){
                    if(Dis[j]==-1) Dis[j]=b[pos][j]+Dis[pos];
                    else Dis[j]=Dis[pos]+b[pos][j];
                }
            }
        }
        cout<<ans+Dis[y]<<'\n';
    }
    return 0;
}
