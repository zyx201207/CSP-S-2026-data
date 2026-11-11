#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,D=21;
typedef long long ll;
typedef pair<int ,int> PI;
priority_queue<PI,vector<PI>,greater<PI> > q;
int c,n,m,dd,Q;
int k;
ll w[M];
int trans[N][N];
PI t[M][D];
int cnt[M],d[N+M];
bool f[N];
vector<PI> e[N+M];
ll ans;
int dijk(int x,int y){
    memset(d,0x3f,sizeof(d));
    memset(f,0,sizeof(f));
    q.push({0,x});
    d[x]=0;
    while(!q.empty()){
        PI h=q.top();
        int u=h.second;
        q.pop();
        if(f[u])continue;
        f[u]=true;
        for(auto p:e[u]){
            int len=p.second,v=p.first;
            if(d[v]>d[u]+len){
                d[v]=d[u]+len;
                q.push({d[v],v});
            }
        }
    }
    return d[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&dd,&Q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
                int idx,tm;
            scanf("%d%d",&idx,&tm);
            t[idx][++cnt[idx]]={i,tm};
        }
    }
    memset(trans,0x3f,sizeof(trans));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=cnt[i];j++){
            int a=t[i][j].first;
            int ta=t[i][j].second;
            e[n+i].push_back({a,ta});
            e[a].push_back({n+i,ta});
            for(int k=j+1;k<=cnt[i];k++){
                int b=t[i][k].first;
                int tb=t[i][k].second;
                trans[a][b]=min(trans[a][b],ta+tb);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(trans[i][j]!=0x3f3f3f3f){
                e[i].push_back({j,trans[i][j]});
                e[j].push_back({i,trans[i][j]});
            }
        }
    }
    while(Q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ans=w[x]+w[y];
        ans+=1LL*dijk(x+n,y+n);
        printf("%lld\n",ans);
    }
    return 0;
}
