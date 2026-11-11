#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005],a[500][100005],t[500][100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        for(int j=1;j<=b;j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
    }
}
