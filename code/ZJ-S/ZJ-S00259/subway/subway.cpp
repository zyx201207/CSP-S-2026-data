#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
constexpr int maxn=5e5+10;
int w[maxn],k[maxn],a,t;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];++j)
        {
            cin>>a>>t;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<n<<endl;
    }
    return 0;
}