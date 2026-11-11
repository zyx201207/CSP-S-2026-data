#include<bits/stdc++.h>
using namespace std;
int w[500010],c,n,m,d,q,k[510];
long long ans=0;
int dis[1010][1010];
vector<int> a[510],t[510];
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
}
void init()
{
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
}
int check()
{
    int f=1;
    for(int i=1;i<=n;i++)
        if(k[i]>2) f=0;
    return f;
}
void solve1()
{
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        for(int j=0;j<k[1];j++)
            if(a[1][j]==x||a[1][j]==y)
                ans+=t[1][j];
        cout<<ans<<endl;
    }
}
void solve2()
{
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        int x_1=0,x_2=0,y_1=0,y_2=0;
        for(int j=0;j<k[1];j++)
            {
                if(a[1][j]==x) x_1=1;
                if(a[1][j]==y) y_1=1;
            }
          for(int j=0;j<k[2];j++)
            {
                if(a[2][j]==x) x_2=1;
                if(a[2][j]==y) y_2=1;
            }
        if(x_1&&y_1)
        {
            for(int j=0;j<k[1];j++)
                if(a[1][j]==x||a[1][j]==y)
                    ans+=t[1][j];
        }
        else if(x_2&&y_2)
        {
            for(int j=0;j<k[2];j++)
                if(a[2][j]==x||a[2][j]==y)
                    ans+=t[2][j];
        }
        cout<<ans<<endl;
    }
}
void solve3()
{
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        int x_1=0,x_2=0,y_1=0,y_2=0,x_3=0,y_3=0;
        for(int j=0;j<k[1];j++)
            {
                if(a[1][j]==x) x_1=1;
                if(a[1][j]==y) y_1=1;
            }
          for(int j=0;j<k[2];j++)
            {
                if(a[2][j]==x) x_2=1;
                if(a[2][j]==y) y_2=1;
            }
            for(int j=0;j<k[3];j++)
            {
                if(a[3][j]==x) x_3=1;
                if(a[3][j]==y) y_3=1;
            }
        if(x_1&&y_1)
        {
            for(int j=0;j<k[1];j++)
                if(a[1][j]==x||a[1][j]==y)
                    ans+=t[1][j];
        }
        else if(x_2&&y_2)
        {
            for(int j=0;j<k[2];j++)
                if(a[2][j]==x||a[2][j]==y)
                    ans+=t[2][j];
        }
        else if(x_3&&y_3)
        {
            for(int j=0;j<k[3];j++)
                if(a[3][j]==x||a[3][j]==y)
                    ans+=t[3][j];
        }
        cout<<ans<<endl;
    }
}
void solve4()
{
    for(int i=1;i<=n;i++)
    {
        dis[a[i][0]][a[i][1]]=t[i][0]+t[i][1];
        dis[i][i]=0;
    }
    floyd();
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        ans+=dis[x][y];
        cout<<ans<<endl;
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
    {

    }
    cout<<ans<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    init();
    if(n==1) solve1();
    else if(n==2) solve2();
    else if(n==3) solve3();
    else if(check()) solve4();
    else solve();
    return 0;
}
