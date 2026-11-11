#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,D=25;
int c,n,m,d,q;
ll f[505][505];
int w[N],k[505];
vector<int> a[505];
vector<pair<int,int>> t[N];
void solve(){
    for(int kk=1;kk<=n;kk++){
        for(int ki=1;ki<=k[kk];ki++){
            int now=a[kk][ki];
            for(int i=0;i<(int)t[now].size();i++){
                for(int j=i+1;j<(int)t[now].size();j++){
                    f[t[now][i].first][t[now][j].first]=min(f[t[now][i].first][t[now][j].first],1ll*t[now][i].second+t[now][j].second);
                }
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||j==k||i==k)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back(0);
        int x,y;
        for(int j=1;j<=k[i];j++){
            cin>>x>>y;
            a[i].push_back(x);
            t[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        sort(t[i].begin(),t[i].end());
    }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)f[i][i]=0;
    solve();
    int x,y;
    while(q--){
        cin>>x>>y;
        ll ans=LLONG_MAX;
        for(auto itx:t[x]){
            for(auto ity:t[y]){
                int l=min(itx.first,ity.first),r=max(itx.first,ity.first);
                ans=min(ans,1ll*f[l][r]+1ll*itx.second+1ll*ity.second);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    // cout<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
}