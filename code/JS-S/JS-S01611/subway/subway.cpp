#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,n,m,d,T;
int w[N],a[N][N],x[N],t[N],vis[N][N];
struct node{int p,x,y,v;};
struct nodee{int x,y,s;};
struct nodeee{int to,len;};
vector<int> v[N];
vector<nodeee> vv[N];
void build(){
    queue<node> q;
    for (int i=1;i<=m;i++) q.push({i,i,0,0});
    while(!q.empty()){
        node tmp=q.front();q.pop();
        int cm=tmp.p,nw=tmp.x,sum=tmp.y,vs=tmp.v;
        //cout<<cm<<" "<<nw<<" "<<sum<<"\n";
        if (cm==nw && sum!=0) continue;
        if (a[cm][nw]==sum && vs) continue;
        if (a[cm][nw]<sum && sum!=0) continue;
        a[cm][nw]=sum;//cout<<1<<"\n";
        for (int i=1;i<=m;i++){
            if (a[nw][i]==0x7f7f7f7f || nw==i) continue;
            //cout<<nw<<" "<<i<<"\n";
            if (sum+a[nw][i]>a[cm][i]) continue;
            if (a[cm][i]==sum && vs) continue;
            q.push({cm,i,sum+a[nw][i],vs});
        }
        //cout<<q.size()<<" ";
    }
    return;
}
int bfs(int x,int y){
    queue<nodee> q;
    q.push({x,x,0});
    memset(vis,0x7f,sizeof vis);
    while(!q.empty()){
        nodee tmp=q.front();q.pop();
        int cm=tmp.x,nw=tmp.y,sum=tmp.s;
        if (vis[cm][nw]<=sum) continue;
        vis[cm][nw]=sum;
        if (nw==y) continue;
        for (auto i:v[nw]){
            if (i==nw) continue;
            q.push({cm,i,sum+1});
        }
    }
    return vis[x][y];
}
int bfs2(int x,int y){
    queue<nodee> q;
    q.push({x,x,0});
    memset(vis,0x7f,sizeof vis);
    while(!q.empty()){
        nodee tmp=q.front();q.pop();
        int cm=tmp.x,nw=tmp.y,sum=tmp.s;
        if (vis[cm][nw]<=sum) continue;
        vis[cm][nw]=sum;
        if (nw==y) continue;
        for (auto i:vv[nw]){
            if (i.to==cm) continue;
            q.push({cm,i.to,sum+i.len});
        }
    }
    return vis[x][y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>T;
    if (12<=c && c<=19){
        for (int i=1;i<=m;i++) cin>>w[i];
        memset(a,0x7f,sizeof a);
        for (int p=1;p<=n;p++){
            int k;cin>>k;
            for (int i=1;i<=k;i++) cin>>x[i]>>t[i];
            for (int i=1;i<=k;i++)
                for (int j=1;j<=k;j++) {
                    if (i==j) continue;
                    v[x[i]].push_back(x[j]);
                    v[x[j]].push_back(x[i]);
                }
        }
        while(T--){
            int x,y;cin>>x>>y;
            cout<<bfs(x,y)<<"\n";
        }
    }
    if (c<=11){
        for (int i=1;i<=m;i++) cin>>w[i];
        memset(a,0x7f,sizeof a);
        for (int p=1;p<=n;p++){
            int k;cin>>k;
            for (int i=1;i<=k;i++) cin>>x[i]>>t[i];
            for (int i=1;i<=k;i++)
                for (int j=1;j<=k;j++) {
                    if (i==j) continue;
                    vv[x[i]].push_back({x[j],t[i]+t[j]});
                    vv[x[j]].push_back({x[i],t[j]+t[i]});
                }
        }
        while(T--){
            int x,y;cin>>x>>y;
            cout<<bfs2(x,y)+w[x]+w[y]<<"\n";
        }
    }
    return 0;
}
