#include <bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>g[N];
int dis[N][N];
bool vis[N];
int main(){
    freopen("hut.in","r",stdin);
    freopen("hut.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=INT_MAX;
        memset(dis,-1,sizeof(dis));
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            dis[u][v]=dis[v][u]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dis[i][j]==-1||dis[j][k]==-1) continue;
                    int cnt=dis[i][j]+dis[j][k];
                    dis[i][k]=(dis[i][k]==-1?cnt:min(dis[i][k],cnt));
                }
            }
        }
        for(int mk=0;mk<(1LL<<n);mk++){
            if(__builtin_popcount(mk)!=k) continue;
            memset(vis,0,sizeof(vis));
            set<int>vt;
            for(int i=0;i<n;i++){
                if((mk>>i)&1) vt.insert(i+1);
            }
            int cnt=0;
            for(auto c:vt){
                if(k<=2) break;
                if(!vis[c]){
                    queue<int>q;
                    cnt++;
                    if(cnt>2) break;
                    q.push(c);
                    vis[c]=1;
                    while(!q.empty()){
                        int x=q.front();
                        q.pop();
                        for(auto d:g[x]){
                            if(vt.find(d)!=vt.end()&&!vis[d]){
                                vis[d]=1;
                                q.push(d);
                            }
                        }
                    }
                }
            }
            int now=0;
            if(cnt<=2){
                for(int i=0;i<n;i++){
                    int cnt=INT_MAX;
                    if(vt.find(i)!=vt.end()) continue;
                    for(auto j:vt){
                        if(i==j||dis[i][j]==-1) continue;
                        cnt=min(cnt,dis[i][j]);
                    }
                    if(cnt==INT_MAX) cnt=0;
                    now=max(now,cnt);
                }
                ans=min(ans,now);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
