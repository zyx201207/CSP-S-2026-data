#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e4+10;
ll C,n,m,d,Q,star,endt,ans,w[M],k[M],a[M][M],t[M][M];
vector<int> g[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        int lst;
        for(int j=1;j<=k[i];j++)
        {
            int u,ti;
            cin>>u>>ti;
            if(j!=1)
            {
                g[lst].push_back(u);
                g[u].push_back(lst);
                lst=u;
            }
        }
    }
    while(Q--)
    {
        ans=0;
        cin>>star>>endt;
        ans+=w[star];
        ans+=w[endt];
        cout<<(endt-star+ans)<<'\n';
    }
    return 0;
}
