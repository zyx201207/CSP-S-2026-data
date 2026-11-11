#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
const int N=1e6+10;
std::vector<int> e[N];
bool flag[N],is[N];
int dis[110][110],D[N],ans=1e9;
class node{
public:
    int v,d;
    friend bool operator<(const node &x,const node &y){
        return x.d<y.d;
    }
};
void DFS(int now,int pre){
    flag[now]=true;
    for(auto v:e[now]){
        if(v==pre) continue;
        if(!is[v]) continue;
        DFS(v,now);
    }
    return ;
}
void dij(int now){
    std::priority_queue<node> q;
    dis[now][now]=0;
    q.push({now,0});
    while(!q.empty()){
        auto k=q.top();
        q.pop();
        int u=k.v;
        for(auto v:e[u]){
            if(dis[now][v]>dis[now][u]+1){
                dis[now][v]=dis[now][u]+1;
                q.push({v,dis[now][v]});
            }
        }
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    std::cin>>c>>t;
    while(t--){
        int n,k;
        std::cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            std::cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        std::memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++)
            dij(i);
        for(int i=0;i<(1<<n);i++){
            int cnt=0;
            std::vector<int> ww;
            for(int j=0;j<n;j++)
                if((1<<j)&i) cnt++;
            if(cnt!=k) continue;
            for(int j=0;j<=n;j++)
                flag[j]=false,is[j]=false;
            for(int j=0;j<n;j++)
                if((1<<j)&i)
                    is[j+1]=true,ww.push_back(j+1);
            cnt=0;
            for(int j=1;j<=n;j++){
                if(is[j]&&!flag[j]){
                    cnt++;
                    if(cnt>2) break;
                    DFS(j,0);
                }
            }
            if(cnt>2) continue;
            int mx=0;
            for(int j=1;j<=n;j++){
                D[j]=1e9;
                for(auto z:ww){
                    D[j]=std::min(D[j],dis[j][z]);
                }
                mx=std::max(mx,D[j]);
            }
            ans=std::min(ans,mx);
        }
        std::cout<<ans<<"\n";
        for(int i=0;i<=n;i++)
            e[i].clear();
        ans=1e9;
    }
    return 0;
}