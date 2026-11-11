#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 507,M = 500007;
int c,n,m,d,q;
int w[M],f[N][N],x,y,ans;
vector <pair <int,int> > sta[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a>>t;
            sta[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j] = 1e17;
    for(int i=1;i<=n;i++) f[i][i] = 0;
    for(int i=1,st1,st2,tm;i<=m;i++){
        for(int j=0;j<sta[i].size();j++){
            for(int k=j+1;k<sta[i].size();k++){
                st1 = sta[i][j].first,st2 = sta[i][k].first,tm = sta[i][j].second + sta[i][k].second;
                f[st1][st2] = min(f[st1][st2],tm);
                f[st2][st1] = min(f[st2][st1],tm);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    while(q--){
        cin>>x>>y;
        ans = 1e17;
        for(int i=0;i<sta[x].size();i++)
            for(int j=0;j<sta[y].size();j++)
                ans = min(ans,w[x] + w[y] + sta[x][i].second + sta[y][j].second + f[sta[x][i].first][sta[y][j].first]);
        cout<<ans<<endl;
    }
}
