#include<bits/stdc++.h>
using namespace std;
const int N=5010;//
typedef long long ll;
int c,T,n,dis[N];
ll d,x[N],ans,ct[N];
vector<int> g[N];
void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(ct,0,sizeof(ct));
    dis[s]=0;ct[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:g[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                ct[v]=ct[u];
                q.push(v);
            }else if(dis[v]==dis[u]+1){
                ct[v]+=ct[u];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ct[i]==2)ans++;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(x[i]-x[j]<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        ans=0;
        for(int i=1;i<=n;i++)bfs(i);
        printf("%lld\n",ans/2);
    }
    return 0;
}
/*
0 1
4 2
1 2 3 4
0 2
2 5 3
3 -2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
