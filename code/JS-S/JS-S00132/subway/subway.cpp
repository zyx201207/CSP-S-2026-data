#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[505],s[505][505];
vector<pair<int,int>> r[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) s[i][j]=4e18;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            for(pair<int,int> x:r[a]) s[x.first][i]=min(s[x.first][i],x.second+t),s[i][x.first]=min(s[i][x.first],x.second+t);
            r[a].push_back({i,t});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                s[i][j]=min(s[i][j],s[i][k]+s[j][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,ans=4e18;
        cin>>x>>y;
        for(pair<int,int> j:r[x]){
            for(pair<int,int> k:r[y]){
                ans=min(ans,s[j.first][k.first]+j.second+k.second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
