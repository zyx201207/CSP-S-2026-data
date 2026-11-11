#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(int i=r;i>=l;i--)
const int N=5e5+5,_N=505;
int c,n,m,d,q,w[N],f[_N][_N];
vector<pii>e[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    fo(i,1,m)
        cin>>w[i];
    fo(i,1,n){
        int k;
        cin>>k;
        fo(j,1,k){
            int x,y;
            cin>>x>>y;
            e[x].push_back({i,y});
        }
    }
    fo(i,1,n)
        fo(j,1,n)
            f[i][j]=(i!=j)*1e18;
    fo(i,1,m)
        for (auto x:e[i])
            for (auto y:e[i])
                if (x.fr!=y.fr)
                    f[x.fr][y.fr]=min(f[x.fr][y.fr],x.sc+y.sc);
    fo(x,1,n)
        fo(i,1,n)
            fo(j,1,n)
                f[i][j]=min(f[i][j],f[i][x]+f[x][j]);
    while (q--){
        int x,y,rs=1e18;
        cin>>x>>y;
        for (auto i:e[x])
            for (auto j:e[y])
                rs=min(rs,f[i.fr][j.fr]+i.sc+j.sc);
        rs+=w[x]+w[y];
        cout<<rs<<'\n';
    }
    return 0;
}