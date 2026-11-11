#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
int t[505][MAXN];
bool can[MAXN];
int aa[MAXN];
int on[MAXN];
vector<int> e[MAXN];
bool vis[MAXN];
int bfs(int x,int y){
    queue<pair<int,int>> q;
    for(int v:e[x]){
        q.push({v,x});
    }
    while(!q.empty()){
        auto [line,cite]=q.front();
        q.pop();
        aa[cite]=0;
        vis[cite]=true;
        if(vis[on[cite]]) continue;
        if(aa[on[cite]]>=aa[cite]+t[line][on[cite]]){
            aa[on[cite]]=aa[cite]+t[line][on[cite]];
            vis[on[cite]]=true;
            vis[x]=false;
            for(int s:e[on[cite]]){
                q.push({s,on[cite]});
            }
        }
    }
    return aa[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    vector<int> w(m+1);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        if(k==1){
            int x;
            scanf("%d",&x);
            can[x]=false;
        }
        else if(k==2){
            int x,y;
            scanf("%d%d%d%d",&x,&t[i][x],&y,&t[i][y]);
            e[x].push_back(i);
            e[y].push_back(i);
            on[x]=y,on[y]=x;
        }
    }
    for(int i=1;i<=q;i++){
        memset(aa,INF,sizeof(aa));
        int ans=0;
        for(int j=1;j<=n;j++) vis[j]=false;
        int x,y;
        scanf("%d%d",&x,&y);
        if(!can[x]||!can[y]) printf("0\n");
        else{
            ans+=w[x]+w[y]+bfs(x,y);
            printf("%d\n",ans);
        }
    }
    return 0;
}
