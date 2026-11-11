#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MANX MAXN
#define MAXM 500005
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
namespace ylf{ void cat(); }
// 15:47 passed
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--) ylf::cat();
    return 0;
}

namespace ylf{
    int w[MAXM];
    vector<pii> line[MAXM]; //line[x] -> x's lines
    int dis[MAXN][MAXN];
    const int inf=1e18;
    void cat(){
        int c,n,m,d,q;
        cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++) cin>>w[i];
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                int a,t;
                cin>>a>>t;
                line[a].push_back({i,t});
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++) dis[i][i]=0;
        for(int id=1;id<=m;id++){
            if(line[id].size()<=1) continue;
            int sz=line[id].size();
            for(int i=0;i<sz;i++){
                for(int j=0;j<sz;j++){
                    int x=line[id][i].first,y=line[id][j].first;
                    dis[x][y]=min(dis[x][y],line[id][i].second+line[id][j].second);
                    dis[y][x]=dis[x][y];
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                if(i==k) continue;
                for(int j=i+1;j<=n;j++){
                    if(j==k) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    dis[j][i]=dis[i][j];
                }
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            int ans=inf;
            int ansl=0,ansr=0;
            for(pii li:line[x]){
                for(pii ri:line[y]){
                    int l=li.first,r=ri.first;
                    int cur=dis[l][r]+li.second+ri.second;
                    if(cur<ans){
                        ans=cur;
                        ansl=l,ansr=r;
                    }
                }
            }
            cout<<ans+w[x]+w[y]<<"\n";
        }
    }
}