#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,x,y;
int w[N],num[N];
vector<pair<int,int>> k[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int kk,v;
        cin>>kk;
        for(int j=1;j<=kk;j++){
            int u,di;
            cin>>u>>di;
            num[u]++;
            k[u].push_back({i,di});
        }
    }
    while(q--){
        cin>>x>>y;
        int ys=w[x]+w[y],ans=1e18;
        for(auto p:k[y]){
            st[p.first]=1;
            for(auto z:k[x]) if(z.first==p.first) ans=min(ans,z.second+p.second+ys);
        }
        for(int i=1;i<=m;i++){
            if(num[i]==1) continue;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
