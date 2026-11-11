#include<bits/stdc++.h>
using namespace std;
int c,n,m,maxn,q,w[1000005],k[100000],vis[1000005],a[10000005],t[1005][1005],b[1005][1005],d[1005][1005],cnt[5000005][25],ct[5000005];
int check(int x,int y){
    int ans=0;
    ans=(w[x]+w[y]);
    int tott=0x3f3f3f3f;
    for(int i=1;i<=ct[x];i++){
        for(int j=1;j<=ct[y];j++){
            int p=cnt[x][i];
            int e=cnt[y][j];
            tott=min(tott,t[x][p]+t[y][e]+d[p][e]);
        }
    }
    return ans+tott;
}
void work3(){
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int u;
            cin>>u;
            cnt[u][++ct[u]]=i;
            b[u][i]=1;
            cin>>t[u][i];
        }
    }
    for(int l=1;l<=m;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[l][i]==1&&b[l][j]==1){
                    d[i][j]=d[j][i]=min(d[i][j],t[l][i]+t[l][j]);
                }
            }
        }
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][l]!=0x3f3f3f3f&&d[j][l]!=0x3f3f3f3f){
                    d[j][i]=d[i][j]=min(d[i][j],d[i][l]+d[j][l]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<check(u,v)<<endl;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>maxn>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    };
    work3();
    return 0;
}
