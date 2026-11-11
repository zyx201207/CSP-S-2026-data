#include<bits/stdc++.h>
using namespace std;
const int MAXN=505,MAXM=500005;
int c,n,m,d,q,tot,ans;
int dist[MAXM],tra[MAXM][MAXN],lea[MAXM],vis[MAXM];
vector<pair<int,int>> e[MAXM];

inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+int(c)-'0'; c=getchar();}
    return x*f;
}

void dijkstra(int now,int des,int lin){
    vis[now]=1;
    if (now==des){
        ans=min(ans,dist[now]+tra[now][lin]);
        vis[now]=0;
        return;
    }
    for (auto i:e[now]){
        int v=i.first,sw=i.second;
        /*if (now==3&&v==5) cout<<"BBBadsad";
        cout<<now<<" "<<lin<<" "<<v<<" "<<sw<<endl;
    for (int i=1;i<=m;i++) cout<<vis[i]<<" ";
    cout<<endl;
    for (int i=1;i<=m;i++) cout<<dist[i]<<" ";
    cout<<endl;*/
        if (vis[v]) continue;
        if (lin==sw){
            dist[v]=dist[now];
            dijkstra(v,des,lin);
        } else {
            dist[v]=dist[now]+tra[now][lin]+tra[now][sw];
            dijkstra(v,des,sw);
        }
    }
    vis[now]=0;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(); n=read(); m=read(); d=read(); q=read();
    for (int i=1;i<=m;i++) lea[i]=read();
    for (int i=1;i<=n;i++){
        int x,st,now; x=read();
        if (x){
            st=read();
            tra[st][i]=read();
            x--;
        }
        while (x--){
            now=read();
            tra[now][i]=read();
            e[st].push_back({now,i});
            e[now].push_back({st,i});
            st=now;
        }
    }
    while(q--){
        ans=1e9;
        int st,ed;
        st=read(); ed=read();
        for (auto i:e[st]){
            memset(dist,0x3f,sizeof(dist));
            memset(vis,0,sizeof(vis));
            int sw=i.second;
            dist[st]=tra[st][sw];
            dijkstra(st,ed,sw);
        }
        cout<<ans+lea[st]+lea[ed]<<"\n";
    }
    return 0;
}
