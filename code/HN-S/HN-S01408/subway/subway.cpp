#include<bits/stdc++.h>
using namespace std;
// #define int long long
struct edge{
    int v,w;
};

vector<vector<edge>>g;

int dis[500005];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        
        // auto [d,u]=pq.top();
        //tmd差点死这了草(一种植物)

        auto i=pq.top();
        int d=i.first;
        int u=i.second;

        pq.pop();
        if(d!=dis[u]){
            continue;
        }
        for(auto j:g[u]){
            int v=j.v;
            int w=j.w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
struct wk{
    int a,t;
};
struct ask{
    int id;
    int u,v;
    int ans;
};
bool cmp1(ask a,ask b){
    return a.u<b.u;
}
bool cmp2(ask a,ask b){
    return a.id<b.id;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int>w(m+1);
    g.resize(m+1);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    vector<vector<wk>>st(n);

    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            st[i].push_back({a,t});
        }
    }
    vector<ask>que(q);
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        que[i]={i,u,v};
    }
    for(auto x:st){
        for(int i=0;i<x.size();i++){
            for(int j=0;j<x.size();j++){
                if(i==j){
                    continue;
                }
                g[x[i].a].push_back({x[j].a,x[i].t+x[j].t});
                g[x[j].a].push_back({x[i].a,x[i].t+x[j].t});
            }
        }
    }

    sort(que.begin(),que.end(),cmp1);
    for(int i=0;i<q;i++){
        
        if(i!=0){
            int u=que[i].u;
            int v=que[i].v;
            if(que[i-1].u==u){
                que[i].ans=dis[v]+w[u]+w[v];
            }
            else{
                dij(u);
                que[i].ans=dis[v]+w[u]+w[v];
            }
        }else{
            dij(que[i].u);
            que[i].ans=dis[que[i].v]+w[que[i].u]+w[que[i].v];
        }
    }
    sort(que.begin(),que.end(),cmp2);
    for(auto i:que){
        cout<<i.ans<<"\n";
    }
    cout<<endl;
    return 0;
}

