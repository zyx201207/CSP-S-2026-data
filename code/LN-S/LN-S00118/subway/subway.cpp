#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[505],k[505],x,y;
int t[505];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(t,0x3f,sizeof(t));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[m];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>x>>y;
            t[x]=min(t[x],y);
        }
    }
    while(q--)
    {
        cin>>x>>y;
        cout<<w[x]+w[y]+t[x]+t[y]<<'\n';
    }
    return 0;
}