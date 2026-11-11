#include<bits/stdc++.h>
using namespace std;
#define int long long
bool Mbe;

const int N=5e5+5;
const int M=5005;

int c,n,m,d,q;
int w[N];

#define pii pair<int,int>
#define fi first 
#define se second 

int low[M][M],D[M][M];
vector<pii > s[N];

void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,v;
            cin>>u>>v;
            s[u].push_back({i,v});
        }
    }

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            low[i][j]=1ll<<61,D[i][j]=1ll<<61;
    for(int i=1;i<=m;i++){
        if(s[i].size()==1) continue;
        for(auto u:s[i]){
            for(auto v:s[i]){
                if(u.fi==v.fi) continue;
                low[u.fi][v.fi]=min(low[u.fi][v.fi],u.se+v.se);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) 
            D[i][j]=low[i][j];
    for(int i=1;i<=n;i++) D[i][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1ll<<61;
        for(auto u:s[x]){
            for(auto v:s[y]){
                // cout<<u.fi<<" "<<v.fi<<" "<<u.se<<" "<<v.se<<"\n";
                ans=min(D[u.fi][v.fi]+u.se+v.se,ans);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }

    return;
}

bool Med;

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T=1;
    while(T--){
        solve();
    }

    // cerr<<fabs(&Mbe-&Med)/1024.0/1024.0<<"MB\n";
    // cerr<<ceil(clock()*1000.0/CLOCKS_PER_SEC)<<"ms\n";

    return 0;
}