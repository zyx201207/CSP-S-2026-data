#include<iostream>
#include<vector>
using namespace std;/*
vector<long long> father;
void init(long long n)
{
    father=vector<long long>(n+1);
    for(int i=0;i<=n;i++)
    {
        father[i]=i;
    }
    return;
}
long long find(long long u)
{
    return u==father[u]?u:father[u]=find(father[u]);
}
bool isSame(long long u,long long v)
{
    return find(u)==find(v);
}*/
bool q;
long long readint()
{
    q=0;
    int c,d;
    long long a=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            q=1;
            return 0;
        }
        d=c;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=a*10+c-48;
        c=getchar();
    }
    if(d=='-')
    {
        a*=-1;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,k;
    c=readint();
    n=readint();
    m=readint();
    d=readint();
    q=readint();
    //init(n);
    vector<long long> w(m+1),a(d+1),t(d+1);
    vector<vector<long long>> dis(m+1,vector<long long>(m+1,1000000000000));
    for(long long i=1;i<=m;i++)
    {
        w[i]=readint();
    }
    for(long long i=0;i<n;i++)
    {
        k=readint();
        for(long long j=0;j<k;j++)
        {
            a[j]=readint();
            t[j]=readint();
            for(long long l=0;l<j;l++)
            {
                if(dis[a[j]][a[l]]>t[j]+t[l])
                {
                    dis[a[j]][a[l]]=t[j]+t[l];
                }
                if(dis[a[l]][a[j]]>t[j]+t[l])
                {
                    dis[a[l]][a[j]]=t[j]+t[l];
                }
            }
        }
    }
    for(long long l=1;l<=m;l++)
    {
        for(long long j=1;j<=m;j++)
        {
            for(long long i=1;i<=m;i++)
            {
                if(i==j)
                {
                    dis[i][j]=0;
                }
                else
                {
                    if(dis[i][j]>dis[i][l]+dis[l][j])
                    {
                        dis[i][j]=dis[i][l]+dis[l][j];
                    }
                }
            }
        }
    }
    long long x,y;
    for(long long i=0;i<q;i++)
    {
        x=readint();
        y=readint();
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
