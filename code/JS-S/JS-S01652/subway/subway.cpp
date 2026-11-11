#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100001],k[100001],a[501][100001],t[501][100001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++)
        {
            if(j%2)cin>>a[i][j];
            else cin>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<'\n';
    }
    return 0;
}

