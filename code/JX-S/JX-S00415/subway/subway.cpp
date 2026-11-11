#include<bits/stdc++.h>
using namespace std;
struct friends{
    int to,from,next,val,num;
} edge[100086];
int tot[100086];
int a[100086],cnt,dist[100086],head[100086],w[100086],T;
bool vis[100086];
void add(int s,int e,int v,int num){
    edge[++cnt].to=e;
    edge[cnt].from=s;
    edge[cnt].next=head[s];
    edge[cnt].val=v;
    head[s]=cnt;
    edge[cnt].num=num;
}
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int nownum[100086];
    memset(nownum,0,sizeof(nownum));
    memset(dist,0x3f3f3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    q.push({0,s});
    dist[s]=0;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]!=0)
        continue;
        vis[u]=1;
        for(int i=head[u];i;i=edge[i].next){
            int x=edge[i].to;
            int val=T;
            if(nownum[u]==edge[i].num)val=0;
            if(dist[x]>dist[u]+val){
                dist[x]=dist[u]+val;
                if(nownum==0)dist[x]+=T;
                q.push({dist[x],x});
                nownum[x]=edge[i].num;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];//
    }
    for(int i=1;i<=n;i++){
        int k,un=-1;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>T;
            if(un==-1){un=a[j];continue;}
            add(a[j],un,T,i);
            add(un,a[j],T,i);
            un=a[j];
        }
    }
    for(int i=1;i<=q;i++){
        int start,destination;
        cin>>start>>destination;
        dijkstra(start);
        cout<<dist[destination]+w[start]+w[destination]<<endl;
    }
    return 0;
}
