#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
ll g[N][N];
int n,m,q,dis[M];
vector<pair<int,int>>line[M];
vector<pair<int,int>>stat[N];
inline bool cmp(const pair<int,int>&a,const pair<int,int>&b){return a.second<b.second;}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&n,&m,&q,&q);
    for(int i=1;i<=m;i++)scanf("%d",dis+i);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        stat[i].reserve(k+2);
        stat[i].resize(k+2);
        for(int j=1;j<=k;j++){
            int u,t;
            scanf("%d%d",&u,&t);
            line[u].push_back({i,t});
            stat[i][j]={u,t};
        }
    }memset(g,0x3f,sizeof(g));
    for(int i=1;i<=n;i++)g[i][i]=0;
    for(int i=1;i<=n;i++)
        for(auto j:stat[i])
            for(auto l:line[j.first])
                g[i][l.first]=min(g[i][l.first],(ll)j.second+l.second);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(int i=i;i<=m;i++)sort(line[i].begin(),line[i].end(),cmp);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=__LONG_LONG_MAX__;
        for(auto i:line[x]){
            if((ll)i.second+line[y][0].second>=ans)break;
            for(auto j:line[y]){
                if((ll)i.second+j.second>=ans)break;
                ans=min(ans,g[i.first][j.first]+i.second+j.second);
            }
        }printf("%lld\n",ans+dis[x]+dis[y]);
    }return 0;
}