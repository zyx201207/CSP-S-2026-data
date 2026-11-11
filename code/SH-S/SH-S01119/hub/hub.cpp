#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
int w[505],t[25][505];
int dp[505][505];
vector<int> line[505],sta[505];
bool vis[505];
void bfs(int start,int ed){
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:st[u]){
            for(int k:line[v]){
                if(dp[u][ed]>=dp[u][k]+t[v])
            }
        }
    }
    for(int v:line[st]){
        if(v==st) continue;
        for(int k:sta[v]){
            if(dp[u][v]>=dp[v])
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        int tmp=i;
        for(int j=1;j<=k;j++){
            int x;
            scanf("%d",&x);
            dp[i][x]=0;
            dp[x][i]=0;
            line[i].push_back(x);
            sta[x].push_back(i);
            scanf("%d",&t[i][x]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
    }
    printf("-1");
    return 0;
}
