#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500050],vis[500050],way[500050][550][2],ans1;
void dfs(int x,int y,int ans,int wi=0,int wj=0){
    if(x==y){
        ans1=min(ans1,ans);
        return ;
    }
    vis[x]=1;
    if(wi=0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=way[i][0][0];j++){
                if(way[i][j][0]==x){
                    dfs(x,y,ans+way[i][j][1],i,j);
                }
            }
        }
    }else{
        for(int i=1;i<=way[wi][0][0];i++){
            if(!vis[way[wi][i][0]]&&i!=wj){
                dfs(way[wi][i][0],y,ans,wi,i);
            }
        }
        for(int i=1;i<=n;i++){
            if(i==wi)continue;
            for(int j=1;j<=way[i][0][0];j++){
                if(way[i][j][0]==x){
                    dfs(x,y,ans+way[i][j][1]+way[wi][wj][1],i,j);
                }
            }
        }

    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","W",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>way[i][0][0];
        for(int j=1;j<=way[i][0][0];j++){

            cin>>way[i][j][0];
            cin>>way[i][j][1];
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        vis[x]=1;
        dfs(x,y,w[x]+w[y]);
        cout<<ans1<<endl;
    }
    return 0;
}
