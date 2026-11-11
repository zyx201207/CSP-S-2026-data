#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
ll w[N];//zhan
vector<int>a[M];//xian
vector<int>t[M];//xian
vector<pair<int,int> >b[N];//zhan
ll g[M][M];//xian
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        a[i].resize(k);
        t[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j]>>t[i][j];
            b[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)g[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto u:b[i]){
            for(auto v:b[i]){
                int x=u.first;
                int y=v.first;
                if(x==y)continue;
                g[x][y]=min(g[x][y],(ll)u.second+v.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto u:b[x]){
            for(auto v:b[y]){
                ans=min(ans,w[x]+w[y]+u.second+v.second+g[u.first][v.first]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}