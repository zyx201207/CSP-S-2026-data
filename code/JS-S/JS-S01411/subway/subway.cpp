#include"bits/stdc++.h"
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500100];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(c>=1&&c<=8){
        int dis[1010][1010];
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                if(i!=j)
                    dis[i][j]=10000000000;
            }
        }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            vector<int>x1;x1.push_back(0);
            vector<int>y1;y1.push_back(0);
            for(int j=1;j<=k;j++){
                int x,y;
                cin>>x>>y;
                x1.push_back(x);
                y1.push_back(y);
            }
            for(int j=1;j<=k;j++){
                for(int j2=j+1;j2<=k;j2++){
                    dis[x1[j]][x1[j2]]=dis[x1[j2]][x1[j]]=y1[j]+y1[j2];
                }
            }
        }
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    if(i!=j&&i!=k&&j!=k&&dis[i][k]+dis[k][j]<dis[i][j]){
                        dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        while(q--){
            int u,v;
            cin>>u>>v;
            cout<<w[u]+w[v]+dis[u][v]<<'\n';
        }
    }
    /*else if(c>=20&&c<=21){
        int whi[500100],wk[500100][10];
        for(int i=1;i<=500000;i++) whi[i]=0;
        for(int i=1;i<=500000;i++) wk[i][1]=wk[i][2]=0;
        int minn=100000000000;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int x,y;
                cin>>x>>y;
                whi[x]+=i;
                wk[x][i]=y;
                if(whi[x]==3) minn=min(minn,wk[x][1]+wk[x][2]);
            }
        }
        while(q--){
            int u,v;
            cin>>u>>v;
            int ans=100000000000;
            if((whi[u]%2)==1&&(whi[v]%2)==1){
                ans=min(ans,wk[u][1]+wk[v][1]);
            }
            if(whi[u]>=2&&whi[v]>=2){
                ans=min(ans,wk[u][2]+wk[v][2]);
            }
            if((whi[u]^whi[v])==3){
                if(whi[u]==1){
                    ans=wk[u][1]+wk[v][2]+minn;
                }
                else ans=wk[u][2]+wk[v][1]+minn;
            }
            cout<<ans+w[u]+w[v]<<'\n';
        }
    }*/
}
