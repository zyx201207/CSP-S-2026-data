#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
int w[500005],f[505][505],k[505];
vector<int> a[505],t[505];
vector<pii> asd[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+1),t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j],asd[a[i][j]].push_back({i,t[i][j]});
    }
    for(int i=1;i<=m;i++){
        int len=asd[i].size();
        for(int l=0;l<len;l++)
            for(int r=l+1;r<len;r++){
                int x=asd[i][l].first,y=asd[i][r].first;
                f[x][y]=f[y][x]=min(f[x][y],asd[i][l].second+asd[i][r].second);
            }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y,ans=LLONG_MAX;
        cin>>x>>y;
        for(auto l:asd[x]){
            for(auto r:asd[y]){
                ans=min(ans,f[l.first][r.first]+l.second+r.second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}