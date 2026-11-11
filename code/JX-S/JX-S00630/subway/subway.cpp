#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500100],kk,aa,tt,cnt,xian[20600][20600];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];

    for(int i=1;i<=n+m;i++)
        for(int j=1;j<=n+m;j++)
            xian[i][j]=0x3f3f3f3f3f;

    for(int i=1;i<=n;i++)
    {
        cin>>kk;
        for(int j=1;j<=kk;j++)
        {
            cin>>aa>>tt;
            xian[i+m][aa]=tt;
            xian[aa][i+m]=tt;
        }
    }
    for(int k=1;k<=n+m;k++)
        for(int i=1;i<=n+m;i++)
            for(int j=1;j<=n+m;j++)
                if(xian[i][j]>xian[i][k]+xian[k][j])
                    xian[i][j]=xian[i][k]+xian[k][j];
    for(int i=1;i<=q;i++)
    {
        int r1,r2;
        cin>>r1>>r2;
        cout<<xian[r1][r2]+w[r1]+w[r2]<<'\n';
    }
    return 0;
}
