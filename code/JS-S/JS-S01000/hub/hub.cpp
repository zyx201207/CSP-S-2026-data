#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> pii;
typedef priority_queue<pii,vector<pii>,greater<pii>> pq;
int e[N],ne[N],idx,h[N],w[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dist[N],n,m;
bool st[N];
int d(){
    pq q;
    q.push({1,0});
    memset(dist,0x3f,sizeof(dist));
    dist[0]=1;
    while(!q.empty()){
        auto t=q.top();
        q.pop();
        int v=t.second;
        if(vis[v])continue;
        vis[v]=true;
        for(int i=h[v];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>dist[u]+w[i]){
                dist[j]=dist[u]+w[i];
                q.push(dist[j],j);
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<d()<<endl;
    return 0;
}
