#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n,k,d,q,m,c,w[N],b[500+N],a[500][N];
int a1[500+N];
void find_ans(int s)
{
    a1[s]=0;
    while(1)
    {
        int u=0;
        for (int j=1;j<=m+n;j++)
        {
            if(a1[j]<a1[u]&&b[j]==0)
            {
                u=j;
            }
        }
        if(u=0)
        {
            break;
        }
        b[u]=1;
        if (u>m)
        {
            for (int j=1;j<=m;j++)
            {
                a1[j]=max(a1[j],a1[u]+a[u-m][j]);
            }
        }
        else
        {
            for (int j=1;j<=n;j++)
            {
                a1[j]=max(a1[j],a1[u]+a[j][u]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.in","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            a[i][j]=INT_MAX;
        }
    }
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        for (int j=1;j<=k;j++)
        {
            int v,l;
            cin>>v>>l;
            a[i][v]=l;
        }
    }
    for (int i=1;i<=n+m;++i)
    {
        a1[i]=INT_MAX;
        if(i==n+m)
            break;
    }
    for (int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        find_ans(x);
        cout<<a1[y]+w[x]+w[y];
        for (int i=1;i<=n+m;i++)
        {
            a1[i]=INT_MAX;
            b[i]=0;
        }
    }
    return 0;
}
