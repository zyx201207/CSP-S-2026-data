#include<bits/stdc++.h>
#define mkp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int N=505,M=5e5+5;
int c,n,m,D,Q,a[M],d[N][N];
ll dis[N][N],ans;
vector<pii>g[N],lk[M];
priority_queue<pli,vector<pli>,greater<pli> >q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            g[i].push_back(mkp(x,t));
            lk[x].push_back(mkp(i,t));
        }
    }
    memset(d,0x7f,sizeof d);
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)g[i].size();j++){
            int x=g[i][j].first,t1=g[i][j].second;
            for(int k=0;k<(int)lk[x].size();k++){
                int y=lk[x][k].first,t2=lk[x][k].second;
                if(i!=y)d[i][y]=min(d[i][y],t1+t2);
            }
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        q.push(mkp(0,i));
        while(q.size()){
            int u=q.top().second;
            ll dist=q.top().first;
            q.pop();
            if(dist>dis[i][u])continue;
            for(int j=1;j<=n;j++){
                if(d[u][j]<0x7f7f7f7f&&dis[i][j]>dis[i][u]+d[u][j]){
                    dis[i][j]=dis[i][u]+d[u][j];
                    q.push(mkp(dis[i][j],j));
                }
            }
        }
    }
    while(Q--){
        ans=1e18;
        int x,y;
        cin>>x>>y;
        for(int i=0;i<(int)lk[x].size();i++){
            for(int j=0;j<(int)lk[y].size();j++)ans=min(ans,a[x]+lk[x][i].second+dis[lk[x][i].first][lk[y][j].first]+lk[y][j].second+a[y]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}

