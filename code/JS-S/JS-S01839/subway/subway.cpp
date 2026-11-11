#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define st string
#define db double
#define ch char
#define bo bool
#define s2 505
#define s3 2005
#define s4 50005
#define s5 500005
#define s6 1000005
#define s7 10000005
using namespace std;
int c,n,m,d,q,w[s5],g[s2][s2],k[s2],dp[s2][s2],ans=0x7f7f7f7f7f7f7f7f,vis2[s5];
int a[s2][s3],t[s2][s3];
struct node{
    int v,z;
    friend bool operator < (node n1,node n2){
        return n1.z>n2.z;
    }
};
int bfs(int s,int o){
    bool vis[s5]={0};
    priority_queue<node> q;
    q.push({s,w[s]});
    while(!q.empty()){
        node x=q.top();
        q.pop();
        int u=x.v,z=x.z;
        if(u==o) return z+w[o];
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=1;i<=n;i++){
            if(a[i][1]==u&&!vis[a[i][2]]){
                q.push({a[i][2],z+t[i][1]+t[i][2]});
            }
            if(a[i][2]==u&&!vis[a[i][1]]){
                q.push({a[i][1],z+t[i][1]+t[i][2]});
            }
        }
    }
    return 0;
}
int bfs2(int s,int o){
    bool vis[s5]={0};
    queue<node> q;
    q.push({s,w[s]});
    while(!q.empty()){
        node x=q.front();
        q.pop();
        int u=x.v,z=x.z;
        if(u==o) return z+w[o];
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==u){
                    for(int h=1;h<=k[i];h++){
                        if(!vis[a[i][h]]){
                            q.push({a[i][h],z+t[i][j]+t[i][h]});
                        }
                    }
                }
            }

        }
    }
    return 0;
}
void dfs(int time,int u){

}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    if(c<=8&&c>0){
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<bfs2(x,y)<<'\n';
        }
    }
    else if(c<=11&&c>0){
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<bfs(x,y)<<'\n';
        }
    }
    else if(c>11){
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<bfs(x,y)<<'\n';
        }
    }
    return 0;
}
