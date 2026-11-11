#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using LLL=__int128;
using pii=pair<int,int>;
const int N=5e5+7,NN=500+7;
const LLL INF=0x7f7f7f7f7f7f7f7f;

int c,n,m,d,q;
int w[N];
int k[N];
LLL dis[NN][NN];
LLL ans;
vector<pii> nodetoline[N];
vector<pair<int,LL>> g[N];

void floyd(){
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==INF) continue;
            for(int k=1;k<=n;k++){
                if(dis[j][k]==INF) continue;
                dis[i][k]=min(dis[i][j]+dis[j][k],dis[i][k]);
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1,a,t;j<=k[i];j++){
            scanf("%d%d",&a,&t);
            nodetoline[a].push_back({i,t});
        }
    }
    memset(dis,0x7f,sizeof dis);
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)nodetoline[i].size()-1;j++){
            for(int k=j+1;k<(int)nodetoline[i].size();k++){
                int u=nodetoline[i][j].first,v=nodetoline[i][k].first;
                LL val=(LL)nodetoline[i][j].second+(LL)nodetoline[i][k].second;
               // cout<<"val "<<val<<endl;
                g[u].push_back({v,val});
                g[v].push_back({u,val});
                dis[u][v]=min(dis[u][v],(LLL)val);
                dis[v][u]=min(dis[v][u],(LLL)val);
            }
        }
    }
    floyd();
    //cout<<"dis "<<dis[1][2]<<"dtx"<<endl;
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        ans=INF;
        for(auto ln1:nodetoline[x]){
            for(auto ln2:nodetoline[y]){
                ans=min(ans,(LLL)w[x]+(LLL)w[y]+(LLL)ln1.second+(LLL)ln2.second+dis[ln1.first][ln2.first]);
            }
        }
        printf("%lld\n",(LL)ans);
    }
    return 0;
}
