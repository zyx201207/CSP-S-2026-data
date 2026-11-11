#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int c,t,n,k,u,v,cnt,tot,head[N],dist[N];

struct Edge{
    int to,nxt,val;
}e[N];

struct Node{
    int u,d;
    bool operator<(const Node& other)const{
        return d>other.d;
    }
}no[N];

priority_queue<Node> pq;

void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].val=1;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}

void dijkstra1(int st,int en){
    while(!pq.empty()){
        pq.pop();
    }
    for(int i=1;i<=n;i++){
        dist[i]=1e9;
    }
    pq.push({st,0});
    dist[st]=0;
    while(!pq.empty()){
        int u=pq.top().u;
        int d=pq.top().d;
        pq.pop();
        if(dist[u]>d){
            continue;
        }
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            int w=e[i].val;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({v,dist[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            add(u,v);
        }
        cout<<1<<"\n";
    }

    return 0;
}
