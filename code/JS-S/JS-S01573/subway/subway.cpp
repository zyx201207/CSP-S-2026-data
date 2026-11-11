#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int M = 5e5+5;
constexpr int N = 505;
const int inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> pii;
int c,n,m,d,q;
int w[M+5];
int mp[N+5][N+5];
vector<vector<pii> > to;
int ans[N+5][N+5];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    to.resize(m+5);
    memset(mp,0x3f,sizeof mp);
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        int k;cin>>k;
        for (int j=1;j<=k;j++){
            int a,t;cin>>a>>t;
            to[a].push_back({i,t});
        }
    }
    for (auto station:to){
        for (auto x:station){
            for (auto y:station){
                mp[x.first][y.first]=min(mp[x.first][y.first],x.second+y.second);
                mp[y.first][x.first]=min(mp[y.first][x.first],x.second+y.second);
            }
        }
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    for (int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=inf;
        for (auto s1:to[x]){
            for (auto s2:to[y]){
                if (s1.first==s2.first){
                    ans=min(ans,+s1.second+s2.second);
                }
                ans=min(ans,mp[s1.first][s2.first]+s1.second+s2.second);
            }
        }
        ans=ans+w[x]+w[y];
        cout<<ans<<"\n";
    }
    return 0;
}