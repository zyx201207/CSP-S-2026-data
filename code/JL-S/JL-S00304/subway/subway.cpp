#include<bits/stdc++.h>
using namespace std;
const int N=5000001,M=10000001;
int c,n,m,d,q,sx,sy;
int pos,cnt,h[N],to[M],nxt[M],val[M],dis[N];
struct st{
    int id,d;
    const bool operator <(st y)const{
        return y.d<d;
    }
};
void add(int u,int v,int w){
    to[++pos]=v;
    nxt[pos]=h[u];
    h[u]=pos;
    val[pos]=w;
    return;
}
void dijkstra(){
    dis[sx]=0;
    priority_queue<st,vector<st> >p;
    p.push({sx,0});
    int u,v,w,d;
    while(!p.empty()){
        u=p.top().id;
        d=p.top().d;
        p.pop();
        if(d>dis[u]){
            continue;
        }
        for(int e=h[u];e;e=nxt[e]){
            v=to[e];
            w=val[e];
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                p.push({v,dis[v]});
            }
        }
    }
    cout<<dis[sy]<<'\n';
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    int u,v,w;
    cnt=m;
    for(int i=1;i<=m;i++){
        cin>>w;
        add(i,++cnt,w);
        add(cnt,i,w);
    }
    int k;
    bool kf;
    for(int i=1;i<=n;i++){
        cin>>k;
        kf=0;
        for(int j=1;j<=k;j++){
            cin>>u>>w;
            add(u+m,++cnt,w);
            add(cnt,u+m,w);
            if(kf){
                add(cnt-1,cnt,0);
                add(cnt,cnt-1,0);
            }else{
                kf=1;
            }
        }
    }
    while(q--){
        cin>>sx>>sy;
        memset(dis,0x3c,sizeof(dis));
        dijkstra();
    }
    return 0;
}
