#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,T,n,k;
int fat[N],fa[N][21],dep[N],dis[N];
bool mk[N];
vector<int> g[N];
int find(int x){
    if(fat[x]==x)  return x;
    return fat[x]=find(fat[x]);
}
void bfs(){
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(mk[i]){
            dis[i]=0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(dis[v]!=-1)  continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
}
void solu1(){
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)  g[i].clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=0x3f3f3f3f;
        for(int s=1;s<1<<n;s++){
            if(__builtin_popcount(s)!=k)  continue;
            for(int i=1;i<=n;i++){
                mk[i]=(s>>(i-1)&1);
                fat[i]=i;
            }
            for(int u=1;u<=n;u++){
                if(!mk[u])  continue;
                for(auto v:g[u]){
                    if(mk[v]){
                        int p=find(u),q=find(v);
                        fat[p]=q;
                    }
                }
            }
            int c1=0,c2=0,f=1;
            for(int i=1;i<=n;i++){
                if(!mk[i])  continue;
                find(i);
                if(!c1)  c1=fat[i];
                else  if(fat[i]!=c1){
                    if(!c2)  c2=fat[i];
                    else  if(fat[i]!=c2){
                        f=0;
                        break;
                    }
                }
            }
            if(!f)  continue;
            bfs();
            int mx=0;
            for(int i=1;i<=n;i++)  mx=max(mx,dis[i]);
            ans=min(ans,mx);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    if(c<=3)  solu1();
    return 0;
}
