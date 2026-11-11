#include <bits/stdc++.h>
using namespace std;
int zz[510],c,m,n,d,k[500010],q,w[500010],t[510][510],a[510][510],ans=0;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];

    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[j][i]>>t[j][i];
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y]+t[x][q]+t[y][q];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[j][i]==x) zz[q]=j;
            }
        }
        for(int i=x;i<=y;i++)
        {
            ans+=t[i][zz[q]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
