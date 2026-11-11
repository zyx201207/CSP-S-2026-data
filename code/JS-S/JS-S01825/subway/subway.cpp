#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
ll c,n,m,d,q,ans;
ll w[N],a[505][N],ti[505][N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++) cin>>a[i][j]>>ti[i][j];
    }
    while(q--){
        int x,y; cin>>x>>y;
        ans+=w[x]+w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=d;j++){
                ans+=ti[i][j];
            }
        }cout<<ans<<endl;
    }
    return 0;
}
