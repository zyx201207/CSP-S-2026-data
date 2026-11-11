#include <bits/stdc++.h>
using namespace std;
struct node{
    long long w;
    long long ti[505];
    bool flag=0;
}a[5005];
struct pqnode{
    int v,line;
    long long d;
};
bool operator<(pqnode a,pqnode b){
    return a.d<b.d;
}
vector<pair<int,int> > g[5005];
bool vis[505][25];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i].w);
    vector<int> lines[505];
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        int lst,x,t;
        for(int j=1;j<=k;j++){
            scanf("%d%d",&x,&t);
            lines[x].push_back(i);
            a[x].ti[i]=t;
            if(j>1){
                g[lst].push_back({x,i});
                g[x].push_back({lst,i});
            }
            lst=x;
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<lines[i].size();j++)
            g[i].push_back({i,lines[i][j]});
    while(q--){
        int s,t;
        scanf("%d%d",&s,&t);
        long long ans=1e18;
        memset(vis,0,sizeof(vis));
        priority_queue<pqnode>pq;
        for(int i=0;i<lines[s].size();i++){
            pqnode tmp;
            tmp.v=s,tmp.d=a[s].w+a[s].ti[lines[s][i]],tmp.line=lines[s][i];
            pq.push(tmp);
        }
        while(!pq.empty()){
            auto tmp=pq.top();
            pq.pop();
            int u=tmp.v;
            long long d=tmp.d;
            int cur=tmp.line;
            //cout<<u<<" "<<cur<<" "<<vis[u][cur]<<endl;
            if(vis[u][cur]) continue;
            vis[u][cur]=1;
            //cout<<u<<endl;
            if(u==t){
                ans=min(ans,d+a[u].ti[cur]+a[u].w);
                continue;
            }
            for(int i=0;i<g[u].size();i++){
                int v=g[u][i].first,l=g[u][i].second;
                if((v==u&&l==cur)||(v!=u&&l!=cur)) continue;
                if(v==u&&l!=cur){
                    pqnode tmp;
                    tmp.v=v,tmp.d=d+a[u].ti[cur]+a[v].ti[l],tmp.line=l;
                    pq.push(tmp);
                }else if(v!=u&&l==cur){
                    pqnode tmp;
                    tmp.v=v,tmp.d=d,tmp.line=cur;
                    pq.push(tmp);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
