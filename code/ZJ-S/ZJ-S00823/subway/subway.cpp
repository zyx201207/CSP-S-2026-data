#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,x,y;
long long a[500005],t[500005];
long long a1[500005],t1[500005],a2[500005],t2[500005],tem[500005],mi=INT_MAX;
struct edge{
    long long v,w;
};
struct node{
    long long id,dist;
    friend bool operator <(const node &a,const node &b){
        return a.dist>b.dist;
    }
}now;
vector <edge> g[1005];
long long dijkstra(long long st,long long en){
    long long dis[1005];
    bool vis[1005];
    for(int i=1;i<=m;i++){
        dis[i]=INT_MAX;
        vis[i]=false;
    }
    dis[st]=0;
    priority_queue <node> q;
    q.push({st,0});
    while(!q.empty()){
        now=q.top();
        q.pop();
        if(vis[now.id]) continue;
        if(now.id==en) return now.dist;
        vis[now.id]=true;
        for(int i=0;i<g[now.id].size();i++){
            if(dis[g[now.id][i].v]>dis[now.id]+g[now.id][i].w){
                dis[g[now.id][i].v]=dis[now.id]+g[now.id][i].w;
                q.push({g[now.id][i].v,dis[g[now.id][i].v]});
            }
        }
    }
    return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(1<=c&&c<=6){
        long long a[305],t[305];
        for(int i=1;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
            for(int j=1;j<=k;j++){
                for(int l=j+1;l<=k;l++){
                    g[a[j]].push_back({a[l],t[j]+t[l]});
                    g[a[l]].push_back({a[j],t[j]+t[l]});
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";
        }
    }
    else if(7<=c&&c<=11){
        long long a1,t1,a2,t2;
        for(int i=1;i<=n;i++){
            cin>>k;
            if(k==1) cin>>a1>>t1;
            else{
                cin>>a1>>t1>>a2>>t2;
                g[a1].push_back({a2,t1+t2});
                g[a2].push_back({a1,t1+t2});
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";
        }
    }
    else if(20<=c&&c<=21){
        if(n==1){
            cin>>k;
            for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
            for(int i=1;i<=q;i++){
                cin>>x>>y;
                cout<<w[x]+t[x]+t[y]+w[y];
            }
        }
        else{
            for(int i=1;i<500005;i++) tem[i]=false;
            cin>>k;
            for(int i=1;i<=k;i++){
                cin>>a1[i]>>t1[i];
                tem[a1[i]]=1;
            }
            cin>>k;
            for(int i=1;i<=k;i++){
                cin>>a2[i]>>t2[i];
                if(tem[a2[i]]==1){
                    mi=min(mi,t1[i]+t2[i]);
                    tem[a2[i]]=-1;
                }
                else tem[a2[i]]=2;
            }
            for(int i=1;i<=q;i++){
                cin>>x>>y;
                long long ans=0;
                ans+=w[x]+w[y];
                if(tem[x]==1&&tem[y]==1) ans+=t1[x]+t1[y];
                else if(tem[x]==1&&tem[y]==2) ans+=t1[x]+t2[y]+mi;
                else if(tem[x]==1&&tem[y]==-1) ans+=t1[x]+t1[y];
                else if(tem[x]==2&&tem[y]==1) ans+=t2[x]+t1[y]+mi;
                else if(tem[x]==2&&tem[y]==2) ans+=t2[x]+t2[y];
                else if(tem[x]==2&&tem[y]==-1) ans+=t2[x]+t2[y];
                else if(tem[x]==-1&&tem[y]==1) ans+=t1[x]+t1[y];
                else if(tem[x]==-1&&tem[y]==2) ans+=t1[x]+t1[y];
                else if(tem[x]==-1&&tem[y]==-1) ans+=min(t1[x],t2[x])+min(t1[y],t2[y]);
            }
        }
    }
   else if(22<=c&&c<=23){
       for(int i=1;i<=n;i++){
           cin>>k;
           for(int i=1;i<=n;i++){
               cin>>k;
               for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
               
           }
       }
   }
   else{
       for(int i=1;i<=n;i++){
           cin>>k;
           for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
           for(int j=1;j<=k;j++){
               for(int l=j+1;l<=k;l++){
                   g[a[j]].push_back({a[l],t[j]+t[l]});
                   g[a[l]].push_back({a[j],t[j]+t[l]});
               }
           }
       }
       for(int i=1;i<=q;i++){
           cin>>x>>y;
           cout<<dijkstra(x,y)+w[x]+w[y]<<"\n";
       }
   }
    return 0;
}
