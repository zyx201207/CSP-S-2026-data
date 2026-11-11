#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20001],tt[500001][500001],cnt=1,ans=0,kd[500001][500001],k[500001],zxz,vis[500001][500001];
void dfs(int xl,int sj,int ed,int st){
    if(st==ed)zxz=min(zxz,sj);
    for(int j=1;j<=n;j++){
        if(vis[st][j] and j!=xl){
            for(int i=1;i<=k[j];i++){
                int jj=(sj+(tt[xl][kd[xl][st]]+tt[j][kd[j][i]]));
                dfs(j,jj,ed,kd[j][i]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){

        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            int x,y;
            scanf("%d",&x,&y);
            tt[i][x]=y;
            kd[i][k[i]]=x;
            vis[x][i]=1;
        }
    }
    for(int l=1;l<=q;l++){
        ans=0;
        int s,e;
        cin>>s>>e;
        zxz=INT_MAX;
        ans+=w[s];
        ans+=w[e];
        dfs(1,0,e,s);
        cout<<ans+zxz<<endl;
    }
    return 0;
}//根本就没有这样的CE
