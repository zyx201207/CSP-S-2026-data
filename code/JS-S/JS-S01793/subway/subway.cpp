#include <bits/stdc++.h>
using namespace std;
int w[500005],ans=INT_MAX;
bool vis[500005];
int a[300][5000];
int k[2000][2000][2];
void dfs(int x,int y,int money){

    if(x==y){
        ans=min(ans,money+w[y]);
    }
    for(int i=0;i<495;i++){


        if(vis[a[x][i]])continue;
        vis[a[x][i]]=1;
        int now=a[x][i];
        for(int j=1;;j++){

            if(k[now][j][0]==0)break;
            if(k[now][j][0]==y){
                dfs(k[now][j][0],y,money+k[now][j][1]+k[now][x][1]);
                return;
            }
            for(int p=1;p<=495;p++){
                if(a[k[now][j][0]][p]!=0&&!vis[a[k[now][j][0]][p]]){
                    dfs(k[now][j][0],y,money+k[now][j][1]+k[now][x][1]);
                    break;
                }
            }

        }
        vis[a[x][i]]=0;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
            int x1,x2;
            cin>>x1>>x2;
            k[i][j][0]=x1;
            k[i][j][1]=x2;

            for(int p=1;p<=495;p++){
                if(!a[x1][p]){
                    a[x1][p]=i;
                    break;
                }
            }
        }
    }
    while(q--){
        memset(vis,0,sizeof vis);
        int x,y;
        cin>>x>>y;
        vis[0]=1;
        dfs(x,y,w[x]);
        cout<<ans<<'\n';
        ans=INT_MAX;
    }
    return 0;
}
