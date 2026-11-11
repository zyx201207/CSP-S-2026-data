#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505][500005];
struct Sub
{
    int w,a,t[505];
    bool l[505];
}st[50005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        cin>>st[i].w;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>k[i][0];
        for (int j=1;j<=k[i][0];j++)
        {
            cin>>k[i][j]>>st[k[i][j]].t[i];
            st[k[i][j]].a=j;
            st[k[i][j]].l[i]=1;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        for (int i=1;i<=n;i++)
        {
            if (st[x].l[i] && st[y].l[i])
            {
                cout<<st[x].w+st[x].t[i]+st[y].w+st[y].t[i]<<endl;
                return 0;
            }
        }
        bool xmp[50005],ymp[50005];
        int minn=1e9,an=1e9,lx[50005][2],ly[50005][2];
        for (int i=1;i<=n;i++)
        {
            if (st[x].l[i])
            {
                for (int j=1;j<=k[i][0];j++)
                {
                    xmp[k[i][j]]=1;
                    lx[k[i][j]][0]=st[k[i][j]].t[i];
                    lx[k[i][j]][1]=i;
                }
            }

        }
        for (int i=1;i<=n;i++)
        {
            if (st[y].l[i])
            {
                for (int j=1;j<=k[i][0];j++)
                {
                    ymp[k[i][j]]=1;
                    ly[k[i][j]][0]=st[k[i][j]].t[i];
                    ly[k[i][j]][1]=i;
                }
            }
        }
        for (int i=1;i<=m;i++)
        {
            if (xmp[i] && ymp[i])
            {
                minn=min(minn,st[x].w+st[x].t[lx[i][1]]+lx[i][0]+ly[i][0]+st[y].t[ly[i][1]]+st[y].w);
            }
        }
        an=min(minn,an);
        cout<<an<<endl;
    }
    return 0;
}
