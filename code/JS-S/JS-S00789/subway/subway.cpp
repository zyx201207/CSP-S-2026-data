#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, B =  5e5+10,LB = 500 + 10;
const long long INF = 1e17+10;
int c,n,m,d,q;
int pre[N],idx = 0;
struct Node{
    int to,nxt;
    long long len;
}a[2*N];
long long way[N][10]
void add(int u,int v,long long len){
    a[++ idx]={v,pre[u]};
    a[idx].nxt=pre[u];
    a[idx].len=len;
    pre[u] = idx;
}
long long lba[LB][LB];
priority_queue<pair<int,int>>vector<pair<int,int>>greater<pair<int,int>>pq;
void bfs(int s){
    memset(vis,false,sizeof(vis));
    pq.push{(0,s)};
    while(!q.empty()){
        auto p = pq.top();
        pq.top();
        int lenn =p.first,h=p.second;
        if([vis[i]){
            vis[i]=true;
            if(bia[s][h]=INF){
                lba[s][h] = lenn;
                lba[h][s]=lenn;
            }else{
                continue
            }
            for(int i = pre[h];i;i = a[i].nxt){
                int to = a[i].to,le = a[i].le;
                if(vis[to] = INF)
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out""w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    scanf("%lld",&w[i]);
    for (int i = 1;i<= n;i++){
        for(int j = 1; j<=k,j++)
        int k;
        scanf("%d",&k);
        for (int j = 1;j<= k;j++){
            scanf("%d%d",&x,&t);
            a[x][++a[x][0]

        }
        for(i = 1;i <= n;i++){
            for(int j= 1,j<=n,j++){
                if(i == j){
                    lba[i][j] = 0;
                }else{
                    lba[i][j]=INF
                }

            }
        }
        for(i = 1;i <= n;i++){
            for(int j = 1;j <=a[i][0];k++){
                for(int k = 1,k <= a[i][0];k++){
                    int u = way[i][j],v=way[i][k]
                    lba[j][k]=ln[x][k]+ln[x][j];
                    lba[k][j]=lba[j][k]
                    add(u,v,lba[i][j])
                }
            }
        }
        for(int i =1,i<= n, i++)
    }
    int x, y;
    while(q--){
        scanf("%d%d",&x,&y);
        for(int i = 1; i<=way[y][0];j++){
            int u = way[x][i],v = way[y][i];
            ans = min(lba[x][y])
        }
    }
    return 0;
}
