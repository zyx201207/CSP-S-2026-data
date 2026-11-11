#include<bits/stdc++.h>
using namespace std;
const int N=500001,M=500002;
int pos,h[N],to[M],nxt[M],val[M],dis[N],r[N];
int c,t,n,k,sx;
struct st{
    int id,d;
    const bool operator <(st y)const{
        return y.d<d;
    }
};
bool cmp(int x,int y){
    return x>y;
}
void init(){
    pos=0;
    memset(r,0,sizeof(r));
    memset(h,0,sizeof(h));
    memset(to,0,sizeof(to));
    memset(nxt,0,sizeof(nxt));
    memset(val,0,sizeof(val));
    memset(dis,0x3c,sizeof(dis));
    return;
}
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
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    int u,v,ans;
    while(t--){
        cin>>n>>k;
        init();
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            r[u]++;
            r[v]++;
            add(u,v,1);
            add(v,u,1);
        }
        if(n==k){
            cout<<1<<'\n';
            continue;
        }
        ans=0;
        if(k==1){
            for(int i=1;i<=n;i++){
                memset(dis,0x3c,sizeof(dis));
                sx=i;
                dijkstra();
                for(int i=1;i<=n;i++){
                    ans=max(ans,dis[i]);
                }
            }
            cout<<ans<<'\n';
        }else if(k==2){
            int anss=1e9;
            for(int i=1;i<=n;i++){
                ans=0;
                for(int j=i+1;j<=n;j++){
                    memset(dis,0x3c,sizeof(dis));
                    sx=i;
                    dijkstra();
                    sx=j;
                    dijkstra();
                }
                for(int j=1;j<=n;j++){
                    ans=max(ans,dis[j]);
                }
                anss=min(ans,anss);
            }
            cout<<anss<<'\n';
        }else{
            sort(r+1,r+n+1,cmp);
            for(int i=1;i<=k;i++){
                sx=i;
                dijkstra();
            }
            for(int i=1;i<=n;i++){
                ans=max(ans,dis[i]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
