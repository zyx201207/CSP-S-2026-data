#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,T,n,k,dep[N],dp[N][25],p[N],vis[N],dd[N],ff;
vector<int>v[N];
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=1;(1<<i)<=dep[x];i++)dp[x][i]=dp[dp[x][i-1]][i-1];
    for(auto it:v[x])if(it!=fa)dfs(it,x);
    return;
}
int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    for(int i=20;i>=0;i--)if(dep[dp[y][i]]>=dep[x])y=dp[y][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)if(dp[x][i]!=dp[y][i])x=dp[x][i],y=dp[y][i];
    return dp[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
void D(int x){
    vis[x]=1;
    for(auto it:v[x])if(p[it]&&!vis[it])D(it);
    return;
}
int bfs(int x){
    queue<int>q;
    for(int i=1;i<=n;i++)dd[i]=-1;
    q.push(x),dd[x]=0;
    while(!q.empty()){
        int t=q.front();q.pop();
        if(p[t])return dd[t];
        for(auto it:v[t]){
            if(~dd[it])continue;
            dd[it]=dd[t]+1,q.push(it);
        }
    }
    return -1;
}
void DFS(int step){
    if(step>n){
        int cc=0;
        for(int i=1;i<=n;i++)if(p[i])cc++;
        if(cc^k)return;
        for(int i=1;i<=n;i++)vis[i]=0;
        int res=0,ans=0;
        for(int i=1;i<=n;i++)if(p[i]&&!vis[i])D(i),res++;
        if(res>2)return;
        for(int i=1;i<=n;i++)ans=max(ans,bfs(i));
        ff=min(ff,ans);
        return;
    }
    p[step]=1,DFS(step+1);
    p[step]=0,DFS(step+1);
    return;
}
void work(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        v[i].clear();
        for(int j=0;j<=20;j++)dp[i][j]=0;
    }
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    if(c<=3){
        ff=1e9,DFS(1),cout<<ff<<"\n";
        return;
    }
    cout<<(n/2+1-k)/4+1<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)work();
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
