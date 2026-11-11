#include<bits/stdc++.h>
using namespace std;
int w[500005],a[500005][500005],t[500005][500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int r=1;r<=q;r++)
    {
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
                if(a[i][j]==x) break;
            for(int j=1;j<=k;j++)
               {
                   ans+=t[i][j];
                   if(a[i][j]==y) break;
               }
        }
       cout<<ans<<endl;
    }
    return 0;
}
