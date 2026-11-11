#include<bits/stdc++.h>
using namespace std;



const int M=2e4+5,N=2e4+5;

struct  node{
    int dis,pos;
    bool operator <(const node &b)const{
        return b.dis<dis;
    }
};
struct edge{
    int to ,next ,dis;
}e[M];
int c,n,m,d,r,cnt;
int head[N],dis[N][N];
bool vis[N];
void add_edge(int u,int v,int d){
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
priority_queue<node> q;
int dij(int s,int r){
    if(dis[s][r]){
        return dis[s][r];
    }
    for(int i=1;i<=cnt*2;i++){
        dis[s][i]=0x3f3f3f3f;
    }
    dis[s][s]=0;
    q.push((node){0,s});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int x=tmp.pos;
        if(vis[x])continue;
        vis[x]=1;
        for(int i=head[x];i;i=e[i].next){
            int y=e[i].to;
            if(dis[s][y]>dis[s][x]+e[i].dis){
                dis[s][y]=dis[s][x]+e[i].dis;
                q.push((node){dis[s][y],y});
            }
        }
    }
    return dis[s][r];
}
void init(){
    while(!q.empty()){
        q.pop();
    }
    memset(vis,0,sizeof(vis));
}

//as 11 test point
int w[N];
node a[N];
int k;

int main(){
    freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>r;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){

        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j].pos>>a[j].dis;

                for(int p=1;j-p>=1;p++)
                    add_edge(a[j-p].pos,a[j].pos,a[j].dis+a[j-p].dis);


        }

    }
    for(int i=1;i<=r;i++){
        int rx,ry;
        cin>>rx>>ry;
        init();
        if(rx<ry){
            cout<<dij(rx,ry)+w[rx]+w[ry]<<endl;
        }else{
             cout<<dij(ry,rx)+w[rx]+w[ry]<<endl;
        }



    }
    return 0;
}
//rp+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
