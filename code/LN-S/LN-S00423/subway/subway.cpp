#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005]={0},k[505]={0};
int a[505][500005]={0};
int t[505][500005]={0};
int xx=0;
int yy=0;
bool z[505][500005]={0};
long long sum,minn;
void r(int x,int y);
void l(int x,int y)
{
    for(int j=1;j<=n;j++)
    {
        for(int b=1;b<=n;b++)
        {
            if(!(z[j][x]&&z[b][y])) continue;
            sum+=t[j][x];
            sum+=t[b][y];
            r(j,b);
            sum-=t[j][x];
            sum-=t[b][y];
        }
    }
    return;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j];
            z[i][a[i][j]]=1;
            cin>>t[i][a[i][j]];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>xx>>yy;
        minn=0x3f3f3f;
        l(xx,yy);
        minn+=w[xx];
        minn+=w[yy];
        cout<<minn;
        if(i!=q) cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
void r(int x,int y)
{
    for(int j=1;j<=m;j++)
    {
        for(int b=1;b<=m;b++)
        {
            if(!(z[x][j]&&z[y][b])) continue;
            if(j==b)
            {
                minn=min(sum,minn);
                return;
            }
            sum+=t[x][j];
            sum+=t[y][b];
            l(j,b);
            sum-=t[x][j];
            sum-=t[y][b];
        }
    }
    return;
}
