#include<bits/stdc++.h>
using namespace std;
const int N=520,M=6e5+10,inf=1e9;
int c,n,m,d,q;
int w[M];
vector<pair<int,int>>ex[M];
struct Edge{int id,val;};
vector<Edge>g[M];
/*
struct Edge{
    int id,to,val;
}edge[M];
int tot,head[M];
void add(int u,int v,int w){
    edge[++tot]={v,head[u],w};
    head[u]=tot;
}*/
void add(int u,int v,int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}
int dis[M];
int res[N][N];
bool vis[M];
int tb[N],ct[N];
void dij(int s){
    priority_queue<pair<int,int>>pq;
    for(int i=1;i<=n+m;++i)dis[i]=inf,vis[i]=false;
    vis[s]=1;dis[s]=0;
    pq.push({0,s});
    while(pq.size()){
        int u=pq.top().second,dd=-pq.top().first;pq.pop();
        //cout<<"chuzhan :"<<u<<' '<<dd<<endl;
        vis[u]=true;
        for(int i=0;i<g[u].size();++i){
            if(dis[g[u][i].id]>dd+g[u][i].val){
                dis[g[u][i].id]=dd+g[u][i].val;
                //cout<<"zhuanyi: "<<g[u][i].id<<'-'<<u<<'='<<dd<<'+'<<g[u][i].val<<endl;
                if(!vis[g[u][i].id])pq.push({-dis[g[u][i].id],g[u][i].id});
            }
        }
    }
    for(int i=1;i<=n;++i)res[s][i]=dis[i];
    //for(int i=1;i<=n+m;++i)cout<<"dis: "<<s<<' '<<i<<' '<<dis[i]<<endl;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)scanf("%d",&w[i]);
    for(int i=1,k,a,t;i<=n;++i){
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&a,&t);
            add(i,a+n,t);
            ex[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;++i){
        dij(i);
        //for(int j=1;j<=n;++j)printf("res[%d][%d]=%d\n",i,j,res[i][j]);
        //cout<<endl;
    }
    for(int i=1,s,t;i<=q;++i){
        scanf("%d%d",&s,&t);
        int ans=inf;
        for(int i=1;i<=n;++i)tb[i]=ct[i]=0;
        for(int j=0;j<ex[s].size();++j){
            int l=ex[s][j].first,c1=ex[s][j].second;
            for(int k=0;k<ex[t].size();++k){
                int r=ex[t][k].first,c2=ex[t][k].second;
                ans=min(ans,res[l][r]+c1+c2+w[s]+w[t]);
            }
        }
        printf("%d\n",ans);
    }
    /*
    for(int i=1;i<=n;++i){
        for(int j=head[i];j=edge[j].to;j){
            cout<<i<<' '<<edge[j].id<<' '<<edge[j].val<<endl;
        }
    }*/
    return 0;
}
//Many years after I graduated, in the mild light of sunset, I recalled a moment when I secretly wrote down this sentence, exactly, the sentence of my distant childhood...
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
