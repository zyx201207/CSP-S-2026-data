#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c,d,q;
const int MAXN=5e5+5;
int v[MAXN],a[505][MAXN],t[505][MAXN];
struct eeee{
    int v,w;
};
        vector<eeee>g[MAXN];
        int vis[MAXN];
void dfs(int u,int y,int as){
    for(auto gg : g[u]){
        int v=gg.v,w=gg.w;
        if(!vis[v]){
            as+=gg.w;
            if(v==y){
                cout<<as<<endl;
                return;
            }
            dfs(v,y,as);
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(n<=50&&m<=300&&q<=200){
        int edge[500][500]={},dirt[500]={};
        memset(dirt,0x3f3f3f3f,sizeof(dirt));memset(edge,0x3f3f3f3f,sizeof(edge));
        for(int i=1;i<=m;i++)cin>>v[i];
        for(int i=1,k;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a[i][j]>>t[i][j];
            }

            for(int j=1;j<=k;j++){
                for(int c=j+1;c<=k;c++){
                    edge[a[i][j]][a[i][c]]=min(t[i][c],edge[a[i][j]][a[i][c]]);
                    edge[a[i][c]][a[i][j]]=min(t[i][j],edge[a[i][c]][a[i][j]]);
                }
            }
        }
        for(int i=1;i<=q;i++){
                memset(vis,0,m);
            int x,y;
            cin>>x>>y;
            queue<int> qq;
            qq.push(x);
            dirt[x]=v[x];
            while(!qq.empty()){
                auto u=qq.front();qq.pop();
                vis[u]=1;
                for(int j=1;j<=m;j++){
                    if(edge[u][j]<=0x3f3f3f3f){
                        if(!vis[j]){
                            qq.push(j);
                        }
                        dirt[j]=min(dirt[j],dirt[u]+edge[u][j]+edge[j][u]);
                    }
                }
            }
            cout<<dirt[y]+v[y]<<endl;

        }
    }else if(q<=2000&&n>1000){
        int cnt=0;
        for(int i=1;i<=m;i++)cin>>v[i];
        for(int i=1,k;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a[i][j]>>t[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            queue<int>qq;
            memset(vis,0,m);
            bool fl=0;
            int x,y;
            cin>>x>>y;
            qq.push(x);
            while(!qq.empty()){
                    if(fl)break;
                auto u=qq.front();qq.pop();
                if(qq.empty())cnt++;
                vis[u]=1;
                for(int j=1;j<=n;j++){
                    if(a[j][x]){
                        for(int k=1;k!=0;k++){
                            if(!vis[a[j][k]]){
                                qq.push(a[j][k]);
                            }
                            if(a[j][k]==y&&!fl){
                                cout<<cnt;
                                fl=1;
                                break;
                            }
                        }
                    }
                }
            }
        }



    }else{

        for(int i=1;i<=m;i++)cin>>v[i];
        for(int i=1,k;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a[i][j]>>t[i][j];
            }if(k>1){
                g[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
                g[a[i][2]].push_back({a[i][1],t[i][2]+t[i][1]});
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            memset(vis,0,m);
            dfs(x,y,0);
        }
    }

    return 0;
}
