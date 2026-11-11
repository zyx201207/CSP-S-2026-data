#include<bits/stdc++.h>
using namespace std;
int n,k,c,t;
vector<int>G[20];
int vis[20],dis[20][20];
void bfs(int s){
    for(int i=1;i<=n;i++)dis[s][i]=INT_MAX;
    queue<int>q;
    q.push(s);
    vis[s]=1;
    dis[s][s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(dis[s][u]+1<dis[s][v])dis[s][v]=dis[s][u]+1;
            if(vis[v])continue;
            vis[v]=1;
            q.push(v);
        }
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
            int mxd=INT_MIN;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int t=0;t<(1<<n);t++){
            int m=t,cnt=0;
            while(m){
                cnt+=m%2;
                m/=2;
            }
            if(cnt!=k)continue;
            int sum=0;
            for(int i=0;i<n;i++){
                if(1<<i&k){
                    if(!vis[i+1]){
                        bfs(i+1);
                        sum++;
                    }
                }
            }
            if(sum<=2){
                for(int i=0;i<n;i++){
                    if(1<<i&k){
                        memset(vis,0,sizeof(vis));
                        bfs(i);
                    }
                    for(int j=0;j<n;j++){
                        if(1<<j&k){
                            mxd=max(dis[i][j],mxd);
                        }
                    }
                }
            }
        }
        cout<<mxd<<'\n';
    }
}
