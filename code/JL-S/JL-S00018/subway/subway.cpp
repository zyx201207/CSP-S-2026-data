#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d,de[505][505],k[505];
vector<int>gg[200005];
void floyd()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                de[j][k]=min(de[j][k],de[j][i]+de[i][k]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m),a[505];
    map<int,int> t[505];
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) de[i][j]=0;
            else de[i][j]=0x3f3f3f3f;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i][x]=y;
            gg[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j:a[i])
        {
            for(int l:gg[j])
            {
                if(l!=i)
                {
                    //cout<<t[i][j]<<' '<<t[l][j]<<'\n';
                    de[i][l]=min(de[i][l],t[i][j]+t[l][j]);
                    de[l][i]=de[i][l];
                }
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<de[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    floyd();
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<de[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int minn=0x3f3f3f3f;
        for(int i:gg[x])
        {
            for(int j:gg[y])
            {
                if(minn>t[i][x]+de[i][j]+t[j][y])
                {
                    minn=t[i][x]+de[i][j]+t[j][y];
                }
            }
        }
        cout<<minn+w[x]+w[y]<<'\n';
        //cout<<w[x]<<' '<<w[y]<<' '<<c1<<' '<<c2<<' '<<c3<<'\n';
    }
}
/*
2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
