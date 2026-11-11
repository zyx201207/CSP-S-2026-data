#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int g[10010][10010],a[520][10010],w[100010],t[10010][10010],k[520];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,INF,sizeof(g));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int l=1;l<=k[i];l++){
                g[a[i][j]][a[i][l]]=g[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
            }
        }
    }
    for(int l=1;l<=m;l++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(g[i][l]!=INF&&g[l][j]!=INF) g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
            }
        }
    }
    int x,y;
    while(q--){
        cin>>x>>y;
        int ans=w[x]+w[y]+g[x][y];
        cout<<ans<<endl;
    }
    return 0;
}
