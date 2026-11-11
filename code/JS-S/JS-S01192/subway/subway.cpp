#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<'\n'
#define zero(a) memset(a,0,sizeof a)
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
const int MAX=1e15;
vector<pair<int,int> >sub[500010];
int w[500010],dis[505][505];
int c,n,m,d,k,q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        int A,Ti;
        while(k--){
            cin>>A>>Ti;
            sub[A].pb({i,Ti});
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i!=j) dis[i][j]=MAX;
        }
    }

    for(int i=1;i<=m;i++){
        for(auto F:sub[i]){
            for(auto T:sub[i]){
                if(F.fi==T.fi) continue;
                dis[F.fi][T.fi]=min(dis[F.fi][T.fi],F.se+T.se);
                dis[T.fi][F.fi]=min(dis[F.fi][T.fi],dis[T.fi][F.fi]);
            }
        }
    }
   // cout<<dis[1][2]<<" "<<dis[2][1]<<endl;
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dis[i][k]==MAX || dis[k][j]==MAX) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int L,R;
    while(q--){
        cin>>L>>R;
        int ans=MAX;
        for(auto F:sub[L]){
            for(auto T:sub[R]){
                ans=min(ans,dis[F.fi][T.fi]+F.se+T.se);
            }
        }
        cout<<(ans+w[L]+w[R])<<endl;
    }
    return 0;
}
//15:26
