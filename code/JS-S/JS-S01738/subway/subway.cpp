#include <bits/stdc++.h>
using namespace std;
const int N=500505;
//priority_queue
//bool operator <(const qwe&)const{}
int id,n,m,d,Q;
int dist[N];
int a[500505];
bool b[N];
int h[N],e[N*2],ne[N*2],w[N*2],idx;
void add(int a,int b,int c){
    e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
int qwe(int start,int finish){
    memset(dist,0x3f,sizeof(dist));
    memset(b,false,sizeof(b));
    dist[start]=a[start];
    priority_queue<pair<int,int>>q;
    q.push({dist[start],start});
    while(q.size()){
        auto uu=q.top();
        int u=uu.second;
        q.pop();
        if(b[u])continue;
        for(int i=h[u];~i;i=ne[i]){
            int v=e[i];
            if(dist[v]>dist[u]+w[i]+a[u]+a[v]){
                dist[v]=dist[u]+w[i];
                q.push({dist[v],v});
                if(v==finish)return dist[finish]+a[finish];
                //<<u<<' '<<v<<' '<<dist[u]<<' '<<dist[v]<<' '<<a[u]<<' '<<w[v]<<'\n';
            }
        }
        b[u]=true;
    }
    //for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
    //cout<<'\n';
    return dist[finish]+a[finish];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    idx=0;
    memset(h,-1,sizeof(h));
    cin>>id>>n>>m>>d>>Q;

    for(int i=1;i<=m;i++){
        cin>>a[i];
    }//cout<<m<<' ' <<n<<'\n';
    n=n+m;
    for(int i=m+1;i<=n;i++){
        int kc;
        cin>>kc;

        while(kc--){
            int u,w;
            cin>>u>>w;
            add(i,u,w);
            add(u,i,w);
        }
    }
    while(Q--){
        int z,x;
        cin>>z>>x;
        //cout<<1<<'\n';
        cout<<qwe(z,x)<<'\n';
    }





    return 0;
}
