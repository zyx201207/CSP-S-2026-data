#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,r=0;
    char c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        r=r*10+(c-'0');
        c=getchar();
    }
    return r*f;
}
struct edge{
    int x,val;
};
vector<edge> g[500005];
int n,m,d,qq,w[500005],k[500005],v[500005],val[500005],dis[1005][1005],vis[500005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int dijkstar(int s,int z){
    for(int i=1;i<=m;i++){
        dis[s][i]=LONG_LONG_MAX;
        vis[i]=0;
    }
    dis[s][s]=0;
    q.push({0,s});
    while(!q.empty()){
        int diss=q.top().first,u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v:g[u]){
            if(dis[s][v.x]>dis[s][u]+v.val){
                dis[s][v.x]=dis[s][u]+v.val;
                q.push({dis[s][v.x],v.x});
            }
        }
    }
    return w[s]+dis[s][z]+w[z];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    n=read();
    n=read();
    m=read();
    d=read();
    qq=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            v[j]=read();
            val[j]=read();
        }
        for(int j=1;j<=k[i];j++){
            for(int l=1;l<=k[i];l++){
                    if(j!=l)
                g[v[l]].push_back({v[j],val[j]+val[l]});
            }
        }
    }
    while(qq--){
        int s=read(),z=read();
        if(dis[s][z]!=0) cout<<w[s]+dis[s][z]+w[z]<<'\n';
        else cout<<dijkstar(s,z)<<'\n';
    }

    return 0;
}
/*0 25 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
