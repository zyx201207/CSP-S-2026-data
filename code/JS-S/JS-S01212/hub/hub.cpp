#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int INF=0x3f3f3f3f;
int Testid,T;
int n,k;
vector<int>G[N];
int ans;
void init(){
    ans=INF;
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
}
bool vis[N];
int b[N],tot;
map<int,bool>mp;
void dfs(int u,int fa){
    vis[u]=1;
    for(auto v:G[u]){
        if(v==fa)continue;
        if(!mp.count(v))continue;
        dfs(v,u);
    }
}
bool check(){
    if(tot!=k)return 0;
    int col=0;
    for(int i=1;i<=tot;i++){
        if(!vis[b[i]]){
            dfs(b[i],0);
            col++;
        }
    }
    //for(int i=1;i<=tot;i++){
    //    cout<<b[i]<<" ";
    //}
    //cout<<col<<"\n";
    if(col>2)return 0;
    return 1;
}
void dfs2(int u,int fa,int &dis,int d){
    if(vis[u]){
        dis=min(dis,d);
        return;
    }
    for(auto v:G[u]){
        if(v==fa)continue;
        dfs2(v,u,dis,d+1);
    }
}
int main(){
    //freopen("/home/user/Desktop/hub/hub2.in","r",stdin);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>Testid>>T;
    if(Testid==7||Testid==11||Testid==12){
        while(T--){
            cin>>n>>k;
            init();
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
                G[u].push_back(v);
                G[v].push_back(u);
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    vis[i]=vis[j]=1;
                    int anss=0;
                    for(int i=1;i<=n;i++){
                        int dis=INF;
                        dfs2(i,0,dis,0);
                        anss=max(anss,dis);
                    }
                    ans=min(ans,anss);
                    vis[i]=vis[j]=0;
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    while(T--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int mask=1;mask<(1<<n);mask++){
            mp.clear();
            tot=0;
            for(int i=0;i<n;i++){
                vis[i+1]=0;
                if(mask&(1<<i)){
                    b[++tot]=i+1;
                    mp[b[tot]]=1;
                }
            }
            if(check()){
                int anss=0;
                for(int i=1;i<=n;i++){
                    int dis=INF;
                    dfs2(i,0,dis,0);
                    //cout<<i<<" "<<dis<<"\n";
                    anss=max(anss,dis);
                }
                //cout<<mask<<" "<<anss<<"\n";
                ans=min(ans,anss);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
