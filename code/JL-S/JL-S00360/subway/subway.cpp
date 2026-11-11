#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
struct edges{
    int from,to,timefrom,timeto,timesum;
}e[maxn];
int c,n,m,d,q;
int w[maxn],k[maxn],t[maxn][maxn];
int edge[maxn][maxn];
int dfs(int x,int y,int come){
    if(edge[x][y]){
        return e[edge[x][y]].timesum;
    }
    int ans=0x3f;
    for(int i=1;i<=n;i++){
        if(i==come)continue;
        if(edge[x][i]){
            ans=min(dfs(i,y,x)+e[edge[x][i]].timesum,ans);
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>k[i]>>x>>e[i].timefrom>>y>>e[i].timeto;
        edge[x][y]=i;
        edge[y][x]=i;
        e[i].from=x;
        e[i].to=y;
        e[i].timesum=e[i].timefrom+e[i].timeto;
    }
    int ans=0;
    int x,y;
    while(q--){
        cin>>x>>y;
        ans=dfs(x,y,0);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}