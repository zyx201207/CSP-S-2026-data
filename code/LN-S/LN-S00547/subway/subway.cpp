#include <bits/stdc++.h>
using namespace std;
const long long inf=1LL<<62;
int c,n,m,d,q,w[500005];
long long f[505][505];
vector<pair<int,int>> v[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    memset(f,127,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(auto j:v[i]){
            for(auto k:v[i]){
                f[j.first][k.first]=min(f[j.first][k.first],1LL*j.second+k.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]<inf&&f[k][j]<inf){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=inf;
        for(auto i:v[x]){
            for(auto j:v[y]){
                if(f[i.first][j.first]<inf){
                    ans=min(ans,f[i.first][j.first]+i.second+j.second);
                }
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}
