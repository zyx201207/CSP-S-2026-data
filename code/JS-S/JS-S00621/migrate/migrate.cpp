#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,inf=1e9;
int c,t,n;
long long d,a[N];
vector<int>g[N];
bool vis[N];
int dis[N],ct[N];
int ans;
void dij(int s){
    priority_queue<pair<int,int>>pq;
    for(int i=1;i<=n;++i)vis[i]=false,dis[i]=inf,ct[i]=0;
    dis[s]=0,ct[s]=1;
    pq.push({0,s});
    while(pq.size()){
        int u=pq.top().second,dd=-pq.top().first;pq.pop();
        vis[u]=true;
        for(int i=0;i<g[u].size();++i){
            if(dis[g[u][i]]>dd+1){
                dis[g[u][i]]=dd+1;
                ct[g[u][i]]=ct[u];
                //cout<<"zhuanyi: "<<g[u][i].id<<'-'<<u<<'='<<dd<<'+'<<g[u][i].val<<endl;
                if(!vis[g[u][i]])pq.push({-dis[g[u][i]],g[u][i]});
            }
            else if(dis[g[u][i]]==dd+1)ct[g[u][i]]+=ct[u];
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1,j=1;i<=n;++i){
            scanf("%lld",&a[i]);
            while(j<i&&a[i]-a[j]>d)++j;
            for(int k=j;k<i;++k){
                g[i].push_back(k);
                g[k].push_back(i);
            }
        }
        ans=0;
        for(int i=1;i<=n;++i){
            dij(i);
            for(int j=1;j<=n;++j)ans+=(ct[j]==2);
        }
        for(int i=1;i<=n;++i)g[i].clear();
        printf("%d\n",ans/2);
    }
    return 0;
}
//Many years after I graduated, in the mild light of sunset, I recalled a moment when I secretly wrote down this sentence, exactly, the sentence of my distant childhood...
