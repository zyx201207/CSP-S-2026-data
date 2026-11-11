#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
const int M=5e2+5;
int c,n,m,d,q1;
int mc[N];
int vis[N];
struct node{
    int id,dis;
};
vector<node> G[N];
bool operator<(node a,node b){
    return a.dis>b.dis;
}
priority_queue<node> q;
int ans[N];
int dj(int a,int b){
    q.push({a,0});
    memset(vis,0,sizeof(vis));
    memset(ans,0x3f,sizeof(ans));
    ans[a]=0;
    while(!q.empty()){
        node x=q.top();
        q.pop();
        if(vis[x.id]==1)continue;
        vis[x.id]=1;
        for(int i=0;i<G[x.id].size();i++){
            node v=G[x.id][i];
            if(ans[v.id]>ans[x.id]+G[x.id][i].dis){
                ans[v.id]=ans[x.id]+G[x.id][i].dis;
                q.push(v);
            }
        }
    }
    return ans[b];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q1;
    for(int i=1;i<=m;i++){
        cin>>mc[i];
    }
    int a,b,e;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=1;j<=a;j++){
            cin>>b>>e;
            G[m+i].push_back({b,e});
            G[b].push_back({m+i,e});
        }
    }
    for(int i=1;i<=q1;i++){
        cin>>a>>b;
        int cnt=dj(a,b);
        cout<<cnt+mc[a]+mc[b]<<endl;
    }
    return 0;
}
