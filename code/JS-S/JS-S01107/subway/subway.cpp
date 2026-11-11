#include<bits/stdc++.h>
using namespace std;
vector<int> stations[505];
long long c,n,m,d,q,w[500005],k[505],ans=23123123,xx,yy,dis[505][505],linjieg[505][505],tmp;
int a[205][2];
long long t[505][505];
bool vis[505][505],lvis[505];
void dfs(int dep,int v,long long quan){
    //cout<<v<<"*\n";
    if(v==yy){
        ans=min(ans,quan);
        return;
    }
    int poss=0;
    for(int i=1;i<=n;i++){
        poss=0;
        for(int j=0;j<k[i];j++){
            //cout<<stations[i][j]<<"-\n";
            if(stations[i][j]==v){
                poss=j+1;
                break;
            }
        }
      // cout<<poss<<"+\n";
        if(!poss)continue;
        for(int j=0;j<k[i];j++){
            if(!lvis[stations[i][j]]){
                lvis[stations[i][j]]=1;
                dfs(dep+1,stations[i][j],quan+t[i][j]+t[i][poss-1]);
                lvis[stations[i][j]]=0;
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c>=7&&c<=11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                linjieg[i][j]=1e13;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            if(k[i]==1){
                cin>>a[i][0]>>a[i][0];
            }
            else{
                cin>>a[i][0]>>t[i][0]>>a[i][1]>>t[i][1];
                linjieg[a[i][0]][a[i][1]]=t[i][0]+t[i][1];
                linjieg[a[i][1]][a[i][0]]=t[i][0]+t[i][1];
            }
        }
        for(int x=1;x<=m;x++){
            int u=x;
            memset(vis[x],0,sizeof(vis[x]));
            for(int i=1;i<=m;i++){
                dis[x][i]=1e16;
            }
            dis[x][u]=0;
            for(int i=1;i<=m;i++){
                vis[x][u]=1;
                long long mi=1e16,mipos=-1;
                for(int j=1;j<=m;j++){
                    if(dis[x][u]+linjieg[u][j]<dis[x][j]){
                        dis[x][j]=dis[x][u]+linjieg[u][j];
                    }
                    if(dis[x][j]<mi&&(!vis[x][j])){
                        mi=dis[x][j];
                        mipos=j;
                    }
                }
                u=mipos;
            }
        }
        while(q--){
            cin>>xx>>yy;
            cout<<dis[xx][yy]+w[xx]+w[yy]<<"\n";
        }
        return 0;
    }
    if(c<=3){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=20;j++){
                t[i][j]=1e16;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=0;j<k[i];j++){
                cin>>tmp;
                stations[i].push_back(tmp);
                cin>>t[i][j];
            }
        }
        while(q--){
            cin>>xx>>yy;
            ans=10000000;
            for(int i=1;i<=m;i++)lvis[i]=0;
            lvis[xx]=1;
            dfs(0,xx,0);
            cout<<ans+w[xx]+w[yy]<<"\n";
        }
        return 0;
    }
   /* if(c<=6){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=n;j++){
                cin>>tmp;
                stations[i].push(tmp);
            }
        }
        while(q--){
            cin>>x>>y;
            ans=10000000;
            dfs(0,x,0);
            if(vis[]){

            }
        }
    }*/
    /*
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=n;j++){
            int tmp=-1;
            cin>>tmp;
            stations[i].push(tmp);
            for(int k=1;k<j;k++){
                g[tmp][stations[i][k]]=
            }
        }
    }
    */
    return 0;
}
