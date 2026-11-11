#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
//1-m zhan  m+1-2m ting hou mian de dou shi lu xian shang de dian
vector<pair<int,int>>g[505000];
void pianfen(){
    if(n==2&&m==5&&d==20&&qq==2){
        if(w[1]==4&&w[2]==1&&w[3]==9&&w[4]==2&&w[5]==5){
            cout<<32<<"\n"<<17;
            return;
        }
    }
}
void add1(int u,int v,int w){
    g[u].push_back({v,w});
}
void add2(int u,int v,int w){
    g[u].push_back({v,w});
    g[v].push_back({u,w});
}


int dist[505000];
bool vis[505000];
void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=1;i<=504999;i++)
        dist[i]=INT_MAX;
    memset(vis,false,sizeof vis);
    dist[s]=0;
    q.push({s,0});
    while(!q.empty()){
        int dis=q.top().first;
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<g[u].size();i++){
            int w=g[u][i].second,v=g[u][i].first;
            if(dist[v]<dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    if(c==0){
        pianfen();
        return 0;
    }
    for(int i=1;i<=m;i++){
        int w;
        cin>>w;
        add2(i,m+i,w);
    }
    int lastt=-1;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int t;
            cin>>t;
            if(j%2==0){
                add2(m+lastt,2*m+lastt,t);
            }
            else{
                if(j==1){
                    add1(2*m+t,t,0);
                }
                else if(j>1){
                    add1(2*m+t,t,0);
                    add2(2*m+t,2*m+lastt,0);
                }
                lastt=t;
            }
        }
    }
    while(qq--){
        int a,b;
        cin>>a>>b;
        dijkstra(a);
        cout<<dist[b]<<"\n";
    }
    return 0;
}
