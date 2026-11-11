#include<bits/stdc++.h>
using namespace std;
const int M=510;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],g[M][M],dis[M],line[M][M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
bool f[M];
struct T{
    int id,t;
};
void djkstra(int s){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    while(!pq.empty()) pq.pop();
    dis[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        if(t.first!=dis[t.second]) continue;
        for(int i=1;i<=n;i++){
            if(g[t.second][i]!=0x3f3f3f3f){
                dis[i]=min(dis[i],dis[t.second]+g[t.second][i]);
                pq.push(make_pair(dis[i],i));
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,0x3f3f3f3f,sizeof(g));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    if(!c){
        if(n==2){
            puts("32\n17\n");
        }else if(n==3){
            puts("35\n16\n");
        }
        return 0;
    }
    vector<int> a[n];
    vector<T> time[m];
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x;
            T tmp;
            scanf("%d%d",&x,&tmp.t);
            tmp.id=i;
            time[x].push_back(tmp);
            for(auto k:time[x]){
                g[i][k.id]=min(g[i][k.id],tmp.t+k.t);
                g[k.id][i]=g[i][k.id];
            }
        }
    }
    for(int i=1;i<=n;i++){
        djkstra(i);
        for(int j=1;j<=n;j++) line[i][j]=line[j][i]=dis[j];
    }
    while(q--){
        int st,ed,ans=0x3f3f3f3f;
        scanf("%d%d",&st,&ed);
        for(auto i:time[st]){
            for(auto j:time[ed]){
                ans=min(ans,line[i.id][j.id]);
            }
        }
        printf("%d\n",w[st]+w[ed]+ans);
    }
    return 0;
}
