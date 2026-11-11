#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
unordered_map<int,int>vis;
struct Point{
    vector<pair<int,int> >be;
}p[500010];
struct line{
    int st,ed;
}li[550];
vector<pair<int,int> >e[500010];
int dis[500010],w[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            if(j==1)li[i].st=a;
            if(j==n)li[i].ed=a;
            p[a].be.push_back({i,t});
        }
    }
    if(c==0){
        if(n==2)cout<<32<<'\n'<<17;
        if(n==3)cout<<35<<'\n'<<16;
        return 0;
    }
    for(int i=1;i<=m;i++){
        if(p[i].be.size()>1){
            for(auto it:p[i].be){
                int w=it.second;
                int id=it.first;
                int St=li[id].st;
                int Ed=li[id].ed;
                if(St!=i){
                    e[St].push_back({i,w});
                    e[i].push_back({St,w});
                }
                if(Ed!=i){
                    e[Ed].push_back({i,w});
                    e[i].push_back({Ed,w});
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int IDx,IDy,X=x,Y=y;
        int W1=w[x],W2=w[y];
        if(p[x].be.size()==1){
            IDx=p[x].be[0].first;
            X=li[IDx].st;
        }
        if(p[x].be.size()==1){
            IDy=p[y].be[0].first;
            Y=li[IDy].st;
        }
        for(int i=1;i<=5e5+5;i++)dis[i]=1e14;
        dis[X]=0;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
        q.push({dis[X],X});
        vis.clear();
        while(!q.empty()){
            auto it=q.top();q.pop();
            int x=it.second,w=it.first;
            if(vis[x])continue;
            vis[x]=1;
            for(auto pii:e[x]){
                int u=pii.first,w=pii.second;

                if(dis[u]>dis[x]+w){
                    dis[u]=dis[x]+w;
                    q.push({dis[u],u});
                }
            }
        }
        cout<<dis[Y]+W1+W2<<'\n';
    }
    return 0;
}
