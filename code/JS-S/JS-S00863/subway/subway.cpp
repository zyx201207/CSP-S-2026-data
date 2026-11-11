#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int M=1005;
int c,n,m,d,q;
int w[M];
int t[N][M],a[N][M],k[N];
int vis[M][M];
vector<pair<int,int>>u[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            u[a[i][j]].push_back({i,t[i][j]});

        }
    }
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=n;i++){
        queue<pair<int,int>>q;
        q.push({i,w[i]});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(auto c:u[x]){
                int now=y+c.second;
                for(int j=1;j<=k[c.first];j++){
                    int nt=t[c.first][j];
                    if(now+nt+w[a[c.first][j]]<vis[i][a[c.first][j]]||vis[i][a[c.first][j]]==-1){
                        vis[i][a[c.first][j]]=now+nt+w[a[c.first][j]];
                        q.push({a[c.first][j],now+nt});
                    }
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<vis[x][y]<<'\n';
    }
    return 0;
}
