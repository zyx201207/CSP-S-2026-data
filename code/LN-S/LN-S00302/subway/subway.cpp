#include <bits/stdc++.h>
using namespace std;

const int MAXM=5e5+5;
int c,n,m,d,q;
int w[MAXM],t[MAXM][501];
int h[2*(MAXM+501)],to[2*(MAXM+501)],nx[2*(MAXM+501)],wgt[2*(MAXM+501)],et=2;
int dis[2*(MAXM+501)];
bool vis[2*(MAXM+501)];

struct question{
    int from=0;
    int to=0;
    int idx=0;
    bool operator<(const question &other){
        return from<other.from;
    }
    question() = default;
};

question qs[100005];
int ans[100005];

inline void add_edge(int u,int v,int w){
    to[et]=v;
    wgt[et]=w;
    nx[et]=h[u];
    h[u]=et++;   
}

inline void add_dedge(int u ,int v,int w){
    add_edge(u,v,w);
    add_edge(v,u,w);
}

void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0x00,sizeof(vis));
    priority_queue<pair<int,int>> pq;
    //cout<<vis[1]<<" "<<dis[1]<<" "<<pq.empty()<<endl;
    pq.push(make_pair(0,s));
    //cout<<pq.empty()<<endl;
    while(!pq.empty()){
        pair<int,int> top=pq.top();
        //cout<<top.second<<" "<<top.first<<endl;
        pq.pop();
        if(vis[top.second]){
            //cout<<"continue"<<endl;
            continue;
        }
        vis[top.second]=true;
        dis[top.second]=-top.first;
        for(int i=h[top.second];i;i=nx[i]){
            //cout<<"in"<<endl;
            int v=to[i];
            //cout<<v<<endl;
            if(!vis[v]){
                //cout<<"push "<<v<<" "<<top.first-wgt[i]<<endl;
                pq.push(make_pair(top.first-wgt[i],v));
            }
        }
    }
}

void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0x00,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int i=h[top];i;i=nx[i]){
            int v=to[i];
            if(!vis[v]){
                vis[v]=true;
                dis[v]=dis[top]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int a_in,t_in;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a_in>>t_in;
            t[a_in][i]=t_in;
            add_dedge(i+MAXM,a_in,t_in);
        }
    }
    int x,y;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        qs[i].from=x;
        qs[i].to=y;
        qs[i].idx=i;
    }
    sort(qs,qs+q);
    int last=-1;
    if(c>=12 && c<=19){
        for(int i=0;i<q;i++){
            //cout<<"quest"<<qs[i].idx<<" "<<qs[i].from<<" "<<qs[i].to<<endl;
            if(qs[i].from!=last){
                bfs(qs[i].from);
                last=qs[i].from;
            }
            //cout<<dis[qs[i].to]<<endl;
            ans[qs[i].idx]=dis[qs[i].to]*wgt[2]+w[qs[i].from]+w[qs[i].to];
        }
        for(int i=0;i<q;i++){
            cout<<ans[i]<<'\n';
        }
    }else{
        for(int i=0;i<q;i++){
            //cout<<"quest"<<qs[i].idx<<" "<<qs[i].from<<" "<<qs[i].to<<endl;
            if(qs[i].from!=last){
                dijkstra(qs[i].from);
                last=qs[i].from;
            }
            //cout<<dis[qs[i].to]<<endl;
            ans[qs[i].idx]=dis[qs[i].to]+w[qs[i].from]+w[qs[i].to];
        }
        for(int i=0;i<q;i++){
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}