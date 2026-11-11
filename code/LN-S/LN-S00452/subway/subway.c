#include<bits/stdc+++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[505][505][25],t[505][505],x,y;
int main()
{
    cin>>q>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        for(int j=1;j<=p;j++)
            cin>>a[i][j][2]>>t[i][j];
    }
    while(q--)
    {
        cin>>x>>y;
        int ans=0;
        ans+=w[x]+t[x]+w[y]+t[y]];
        bfs(x,y);
    }

    return 0;
}
