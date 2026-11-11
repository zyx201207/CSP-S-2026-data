#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int c,n,m,d,q,x,y;
struct edge{
    long long u,v;
};
vector<edge> arr[3005];
long long dis[3005];
bool vis[3005];
void dijkstra(int s,int len){
    for(int i=1;i<=len;i++){
        for(auto &f : arr[i]){
         //  cout<<i<<" "<<f.u<<" "<<f.v<<endl;
        }
    }
    queue<edge> q;
    q.push({s,0});
    vis[0]=true;
    dis[s]=0;
    while(!q.empty()){
        edge t=q.front();
        q.pop();
        int pos=t.u;
        for(auto &f : arr[pos]){
            long long u=f.u,v=f.v;
            if(vis[u]){
                continue;
            }
            if(dis[u]>dis[pos]+v){
                dis[u]=dis[pos]+v;
            }
            //cout<<dis[u]<<endl;
            q.push({u,dis[u]});
        }
        vis[pos]=true;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    int w;
    for(int i=1;i<=m;i++){
        scanf("%d",&w);
        edge t;
        t.u=i+2*m,t.v=w;
        arr[i+m].push_back(t);
        t.u=i+m;
        arr[i+2*m].push_back(t);
    }
    w=0;
    int u=0,preu=0;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d",&u);
            scanf("%d",&w);
            edge t;
            t.u=u,t.v=w;
            arr[u+m*2].push_back(t);
            t.u=u+m*2;
            arr[u].push_back(t);
            if(i>=1){
                t.u=u+m,t.v=0;
                arr[preu].push_back(t);
                t.u=preu;
                arr[u+m].push_back(t);
            }
            preu=u;
        }
    }
    for(int i=0;i<q;i++){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&x,&y);
        dijkstra(x+2*m,3*m);
        printf("%d\n",dis[y+2*m]);
    }
    //kou=u+m,zhantai=u,zhanting=u+2m
    fclose(stdin);
    fclose(stdout);
    return 0;
}
