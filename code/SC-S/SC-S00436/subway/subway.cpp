#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=510,M=5e5+10;
int w[M];
struct node
{
    int id,w;
}p[M][30];
int cnt[M];
int dist[N][N];
int num[N];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
} 
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++)
    {
        num[i]=read();
        for(int j=1;j<=num[i];j++)
        {
            int a=read(),t=read();
            p[a][++cnt[a]]={i,t};
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++)
    {
        dist[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            for(int k=j+1;k<=cnt[i];k++)
            {
                int x=p[i][j].id,y=p[i][k].id;
                dist[x][y]=min(dist[x][y],p[i][j].w+p[i][k].w);
                dist[y][x]=dist[x][y];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++) 
            {
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                dist[j][i]=dist[i][j];
            }
        }
    }
    while(q--)
    {
        int s=read(),t=read();
        int mn=1e18;
        for(int i=1;i<=cnt[s];i++)
        {
            for(int j=1;j<=cnt[t];j++)
            {
                int ss=p[s][i].id,tt=p[t][j].id;
                mn=min(mn,dist[ss][tt]+p[s][i].w+p[t][j].w);
            }
        }
        printf("%lld\n",mn+w[s]+w[t]);
    }
    return 0;
}
