//
#include <iostream>
#include <cmath>
using namespace std;
int ans=99999999;
int w[500007],k[507];
int c,n,m,d,q;
int flag[500007][501];
struct code{
    int p,cost;
}st[501][500007];
void dfs(int pc,int y,int cost){
    if(cost>ans) return;
    if(pc==y){
        ans=min(ans,cost);
        return;
    }
    for(int i=1;i<=n;i++){
        if(flag[y][i]==0) continue;
        for(int j=1;j<=k[i];j++){
            if(st[i][j].p==pc) continue;
            dfs(st[i][j].p,y,cost+st[i][j].cost);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>st[i][j].p>>st[i][j].cost;
            flag[st[i][j].p][i]=1;
        }
    }
    while(q--){
        int x,y;
        ans=99999999;
        cin>>x>>y;
        dfs(x,y,w[x]+w[y]);
        cout<<ans<<endl;
    }
    return 0;
}
