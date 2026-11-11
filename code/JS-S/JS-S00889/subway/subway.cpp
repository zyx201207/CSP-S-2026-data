#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5005;
int c,n,m,tmp,q,w[500005],k[1005],a,t,x,y,cnt;
vector<pair<int,int>>e[N];
bool vis[N];
long long d[N],ans[1005][1005];
void diji(int st,int ed){
    if(ans[st][0])return;
    for(int i=1;i<=cnt+n+m;i++)vis[i]=0,d[i]=1e18;
    memset(d,0x3f,sizeof(d));
    d[x]=0;
    priority_queue<pair<long long,int>>q;
    q.push({0,x});
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(auto [y,w]:e[x]){
            if(d[y]>d[x]+w){
                d[y]=d[x]+w;
                q.push({-d[y],y});
            }
        }
    }
    ans[st][0]=1;
    for(int i=1;i<=m;i++){
        ans[st][i]=d[i];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&tmp,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        int la,lt;
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a,&t);
            cnt++;
            e[cnt+m+n].push_back({a,t});
            e[a].push_back({cnt+m+n,t});
            e[cnt+m+n].push_back({i+m,0});
            e[i+m].push_back({cnt+m+n,0});
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        diji(x,y);
        printf("%lld\n",ans[x][y]+w[x]+w[y]);
    }
    return 0;
}
