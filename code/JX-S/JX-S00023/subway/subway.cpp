#include<bits/stdc++.h>
using namespace std;
long long w[500005];
int c,n,m,d,q;
long long t[505][500005];
int k[505];
long long dist[500005];
struct node{
    int to;
    long long t;
    bool operator<(const node&other)const{
        return t>other.t;
    }
};
vector<int>g[505];
vector<int>l[500005];
void DSB(int s){
    priority_queue<node>q;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().to;
        long long t=q.top().t;
        q.pop();
        for(int s=0;s<l[u].size();s++){
            int i=l[u][s];
            for(int j=0;i<g[i].size();j++){
                int v=g[i][j];
                if(u==v)continue;
                long long d1=t[i][u];
                long long d2=t[i][v];
                long long d=d1+d2;
                if(dist[v]<=dist[u]+d)continue;
                dist[v]=dist[u]+d;
                q.push({v,dist[v]});
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a;
            cin>>a;
            g[i].push_back(a);
            l[a].push_back(i);
            cin>>t[i][a];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            dist[i]=1e18;
        }
        dist[x]=0;
        DSB(x);
        cout<<w[x]+dist[y]+w[y]<<"\n";
    }
    return 0;
}


