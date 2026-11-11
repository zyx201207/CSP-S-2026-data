#include<bits/stdc++.h>
using namespace std;
int inline read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();};
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();};
    return x*f;
}
const int N=5e5+10;
int c,n,m,d,q,w[N],k[N],a[510][N],t[510][N],dis[N],vis[N];
vector<pair<int,int> > g[N];
struct cmp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)const{
        return a.second>b.second;
    }
};
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            a[i][j]=read();
            t[i][j]=read();
        }
        for(int j=1;j<=k[i];j++)
            for(int kn=1;kn<=k[i];kn++){
                if(j==kn)continue;
                g[a[i][j]].push_back({a[i][kn],t[i][j]+t[i][kn]});
                g[a[i][kn]].push_back({a[i][j],t[i][j]+t[i][kn]});
            }
    }
    while(q--){
        for(int i=1;i<=m;i++)dis[i]=INT_MAX,vis[i]=0;
        int x,y;
        x=read();
        y=read();
        priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> qp;
        qp.push({x,0});
        dis[x]=0;
        while(!qp.empty()){
            int u=qp.top().first;
            qp.pop();
            if(vis[u])continue;
            vis[u]=true;
            for(auto p:g[u]){
                int v=p.first;
                int w=p.second;
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    qp.push({v,dis[v]});
                }
            }
        }
        cout<<w[x]+w[y]+dis[y]<<'\n';
    }
    return 0;
}
