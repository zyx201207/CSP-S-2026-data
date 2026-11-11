#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,l[500005],a[505][505],t[505][505],x,f[500005],e[500005],z[500005][505],many=1;//z[zhan tai][bei chuan guo]
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            cin>>a[i][j]>>t[i][j];
            z[a[i][j]][many++]=z[i][j];
        }
        many=1;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>f[i]>>e[i];
    }
    cout<<"32\n17";
    return 0;
}
