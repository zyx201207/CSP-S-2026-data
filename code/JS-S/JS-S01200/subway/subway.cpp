#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[1919810];
int kou[1919810],ting[1919810],d[1919810],vis[1919810];
main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,dd,q;
    cin>>c>>n>>m>>dd>>q;
    for(int i=1,x;i<=m;i++)cin>>x,g[2*i].push_back({2*i+1,x}),g[2*i+1].push_back({2*i,x}),kou[i]=2*i,ting[i]=2*i+1;
    int maxx=2*m+1;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1,x,y,lst=0;j<=k;j++){
            cin>>x>>y,maxx++,g[ting[x]].push_back({maxx,y}),g[maxx].push_back({ting[x],y});
            if(lst)g[maxx].push_back({lst,0}),g[lst].push_back({maxx,0});
            lst=maxx;
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t,s=kou[s],t=kou[t];
        memset(d,0x3f3f3f3f,sizeof d),memset(vis,0,sizeof vis);
        priority_queue<pair<int,int>>q;
        q.push({0,s}),d[s]=0,vis[s]=1;
        while(q.size()){
            int u=q.top().second;
            q.pop();
            for(auto i:g[u]){
                int v=i.first,w=i.second;
                if(d[v]>=d[u]+w&&(!vis[v]))d[v]=d[u]+w,q.push({-d[v],v}),vis[v]++;
            }
        }
        cout<<d[t]<<endl;
    }
}
