#include<bits/stdc++.h>
using namespace std;
int read()
{
    int ret=0,sgn=0,ch=getchar();
    while(ch<'0'||ch>'9')sgn|=ch=='-',ch=getchar();
    while('0'<=ch&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return sgn? -ret:ret;
}
const int maxn=5*1e5+5;//未确定
long long dis[505];
int c,n,m,d,q;
int w[505];
//点个数是m
long long a[505][505];
int inf=0x3f3f3f3f;
bool found=0;
bool check()
{
    for(int i=1;i<=m;i++)if(dis[i]==inf)return 1;
    return 0;
}
int main()
{
    freopen("subway2.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++)
    {
        int tmp[maxn]={0};
        bool tmpflag[maxn]={0};
        int k=0;
        k=read();
        for(int i=1;i<=k;i++)
        {
            int tmpn=0;
            tmpn=read();
            tmp[tmpn]=read();
            tmpflag[tmpn]=1;
        }
        for(int i=1;i<=m;i++)
        {
            if(!tmpflag[i])continue;
            for(int j=1;j<=m;j++)
            {
                if(!tmpflag[j]||(i==j))continue;
                a[i][j]=tmp[i]+tmp[j];
                a[j][i]=tmp[i]+tmp[j];//应该是
            }
            tmpflag[i]=0;
        }

    }

    cout<<endl;
    while(q--)
    {
        int x=0,y=0;
        x=read();y=read();
        for(int i=1;i<=m;i++)if(i!=x)dis[i]=inf;
        int now,last=x;
        while(check())
        {
            int mmin=inf;
            for(int i=1;i<=m;i++)
            {
                if(mmin>a[last][i])
                {
                    mmin=dis[i];
                    now=i;
                }
            }

            for(int i=1;i<=m;i++)
            {
                if(dis[i]>dis[now]+a[now][i])
                {
                    dis[i]=dis[now]+a[now][i];
                }
            }
            last=now;
        }
        cout<<dis[y]+w[x]+w[y]<<'\n';
    }


    return 0;
}
