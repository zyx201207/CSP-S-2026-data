#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
long long c,n,m,d,q,num[M];
long long w[M],dis[N][N];
long long a[M][22],t[M][22];
long long read()
{
    long long sum=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
            sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    //cout<<c<<' '<<n<<" "<<m<<" "<<d<<" "<<q<<endl;
    for(int i=1;i<=m;i++)
        w[i]=read();
    //long long maxx=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=read();
        for(int j=1;j<=tmp;j++)
        {
            long long x,y;
            x=read();y=read();
            //maxx=max(maxx,x);
            num[x]++;
            a[x][num[x]]=i;
            t[x][num[x]]=y;
        }
    }
    //cout<<maxx<<endl;
    /*long long maxl=0;
    for(int i=1;i<=m;i++)
        maxl=max(maxl,num[i]);
    cout<<maxl<<endl;*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=1e18;
    //memset(dis,0x3f3f3f3f,sizeof(dis));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=num[i];j++)
            for(int k=1;k<=num[i];k++)
            {
                int aa=a[i][j],bb=a[i][k];
                dis[aa][bb]=min(dis[aa][bb],t[i][j]+t[i][k]);
                dis[bb][aa]=min(dis[bb][aa],t[i][j]+t[i][k]);
            }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<dis[i][j]<<" ";
        cout<<endl;
    }*/
    while(q--)
    {
        int s=read(),tt=read();
        long long ans=1e18;
        for(int i=1;i<=num[s];i++)
            for(int j=1;j<=num[tt];j++)
                ans=min(ans,dis[a[s][i]][a[tt][j]]+t[s][i]+t[tt][j]);

        //cout<<ans<<endl;
        printf("%lld\n",ans+w[s]+w[tt]);
    }
    return 0;
}
