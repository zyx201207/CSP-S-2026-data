#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000006;
int c,t,n,k;
bool vis[MAXN];
int head[MAXN],cnt;
struct edge{
    int to,va,nex;
}G[MAXN<<1];
inline void init(){
    for(int i=1;i<=n;i++)
        head[i]=0;
    for(int i=1;i<=cnt;i++)
        G[i].to=G[i].nex=G[i].va=0;
    cnt=0;
    for(int i=1;i<=n;i++)
        vis[i]=0;
}
inline void add(int u,int v,int w){
    G[++cnt].nex=head[u];
    G[cnt].to=v;
    G[cnt].va=w;
    head[u]=cnt;
}

inline void dfs(int u,int fa,int state){
    for(int i=head[u];i;i=G[i].nex){
        int v=G[i].to;
        if(v==fa) continue;
        if(state&(1<<(v-1))){
            vis[v]=1;
            dfs(v,u,state);
        }
    }
}
int dis[MAXN];
bool viss[MAXN];
struct Dij{
    int to,va;
    bool operator<(const Dij& a)const{
        return a.va>va;
    }
};
priority_queue<Dij> q;
inline void dij(int s){
    for(int i=1;i<=n;i++){
        dis[i]=INT_MAX;
        viss[i]=0;
    }
    dis[s]=0;
    q.push({s,0});
    while(!q.empty()){
        Dij tot=q.top();
        q.pop();
        if(!viss[tot.to]){
            viss[tot.to]=1;
            for(int i=head[tot.to];i;i=G[i].nex){
                int v=G[i].to,w=G[i].va;
                if(dis[tot.to]+w<dis[v]){
                    dis[v]=dis[tot.to]+w;
                    q.push({v,dis[v]});
                }
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;                                                                                                                       
    while(t--){
        init();
        int ans=INT_MAX;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v,1);
            add(v,u,1);
        }
        for(int state=1;state<(1<<n);state++){
            int count=0;
            vector<int> jd;
            for(int k=0;k<n;k++)
                if(state&(1<<k)){
                    count++;
                    jd.push_back(k+1);
                }
            if(count!=k) continue;
            // for(int i=0;i<jd.size();i++){
            //     cout<<jd[i]<<" ";
            // }cout<<'\n';
            int f=0;
            bool ff=true;
            for(int i=1;i<=n;i++){
                vis[i]=0;
            }
            for(int i=0;i<jd.size();i++){
                if(!vis[jd[i]]){
                    if(f<=2){
                        vis[jd[i]]=1;
                        dfs(jd[i],0,state);
                        f++;
                    }else{
                        ff=false;
                        break;
                    }
                }
            }
            // for(int i=1;i<=n;i++)
            //     cout<<vis[i]<<" ";
            // cout<<'\n';
            if(!ff) continue;
            int sum=0;
            for(int i=1;i<=n;i++){
                bool fff=false;
                for(int k=0;k<jd.size();k++){
                    if(i==jd[k]){
                        fff=true;
                        break;
                    }
                }
                if(!fff){
                    int summ=INT_MAX;
                    dij(i);
                    for(int k=0;k<jd.size();k++){
                        summ=min(summ,dis[jd[k]]);
                    }
                    sum=max(sum,summ);
                }
            }
            ans=min(ans,sum);
        }
        cout<<ans<<'\n';
    }
    return 0;
}//dui pai T1!!!!!!!!!!!!!!!!!!!!!!!
// g++ hub.cpp -o hub -std=c++14 -O2