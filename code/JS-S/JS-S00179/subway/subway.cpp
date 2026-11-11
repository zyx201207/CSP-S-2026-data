#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const int M=2e4+5;
ll c,n,m,d,q,k,x,y,ans,w[M],arr[M],t[M],vis[M],dis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        if(c<=8)dis[i][i]=0;
    }
    if(c<=8){
        for(int i=1;i<=n;i++){
            memset(t,0,sizeof(t));
            memset(arr,0,sizeof(arr));
            cin>>k;
            for(int j=1;j<=k;j++)cin>>arr[j]>>t[j];
            for(int u=1;u<=k;u++){
                for(int v=1;v<=k;v++){
                    if(u==v)continue;
                    int st=arr[u],ed=arr[v];
                    dis[st][ed]=min(dis[st][ed],t[u]+t[v]);
                    dis[ed][st]=dis[st][ed];
                }
            }
        }
        for(int t=1;t<=m;t++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    dis[i][j]=min(dis[i][t]+dis[t][j],dis[i][j]);
                    dis[j][i]=dis[i][j];
                }
            }
        }

        while(q--){
            cin>>x>>y;
            cout<<dis[x][y]+w[x]+w[y]<<'\n';
        }
    }
    else if(c>=12&&c<=15){
        int T;
        vector<int>G[M];
        for(int i=1;i<=n;i++){
            memset(t,0,sizeof(t));
            memset(arr,0,sizeof(arr));
            cin>>k;
            for(int j=1;j<=k;j++)cin>>arr[j]>>t[j];
            T=t[1];
            for(int u=1;u<=k;u++){
                for(int v=1;v<=k;v++){
                    G[arr[u]].push_back(arr[v]);
                    G[arr[v]].push_back(arr[u]);
                }
            }
        }
        while(q--){
            cin>>x>>y;
            int flag=0;
            queue<pair<int,int> >myq;
            memset(vis,0,sizeof(vis));
            myq.push({x,0});
            vis[x]=1;
            while(!myq.empty()){
                auto tp=myq.front();
                myq.pop();
                for(int i=0;i<G[tp.first].size();i++){
                    int nd=G[tp.first][i];
                    if(!vis[nd]){
                        myq.push({nd,tp.second+1});
                        vis[nd]=1;
                    }
                    if(nd==y){flag=1;break;}
                }
                if(flag){
                    cout<<(tp.second+1)*2*T+w[x]+w[y]<<'\n';
                    break;
                }
            }
        }
    }
    return 0;
}
