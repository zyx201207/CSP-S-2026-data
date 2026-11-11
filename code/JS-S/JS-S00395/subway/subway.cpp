#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const ll inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-9;
using namespace std;

const int maxn=505;
const int maxm=500005;
vector<pii> to[maxm];
vector<pii> g[maxn];
ll c,d,m,n,q,a,t,w[maxm],x,y;
ll k[maxn],dis[maxn][maxn];

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    memset(dis,0x3f,sizeof dis);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a,&t);
            to[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=m;i++){
        for(int j1=0;j1<to[i].size();j1++) for(int j2=j1+1;j2<to[i].size();j2++){
            pii u=to[i][j1],v=to[i][j2];
            int U=min(u.first,v.first),V=max(u.first,v.first);
            ll W=u.second+v.second;
            dis[U][V]=min(dis[U][V],W);
        }
    }
    for(int mid=1;mid<=n;mid++) for(int u=1;u<=n;u++) for(int v=u+1;v<=n;v++)
        dis[u][v]=min(dis[u][v],dis[u][mid]+dis[mid][v]);
    for(int i=1;i<=q;i++){
        ll res=inf;
        scanf("%lld%lld",&x,&y);
        if(x==y) res=0;
        for(pii u:to[x]) for(pii v:to[y]){
            int U=min(u.first,v.first),V=max(u.first,v.first);
            ll W=u.second+v.second;
            res=min(res,dis[U][V]+w[x]+w[y]+W);
        }
        printf("%lld\n",res);
    }

    //16:38 Accepted
    //But my subway7 cost 2.019s??!!
    //No way.

    //OK.Now 0.881s.But still close.

    return 0;
}
