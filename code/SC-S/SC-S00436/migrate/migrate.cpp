#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5010;
int cnt[N];
struct node
{
    int x,id,ways;
};
int f[N][N],g[N][N];
int a[N];
int sum[N];
queue<node> q;
int dis(int p,int q)
{
    return a[q]-a[p];
}
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') 
    {
        if(c=='-') f=-f;
        c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    memset(f,0x3f,sizeof(f));
    memset(g,0,sizeof(g));
    while(T--)
    {
        int n=read(),d=read();
        int ans=0;
        for(int i=1;i<=n;i++) a[i]=read();
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) cnt[j]=0;
            for(int j=1;j<=n;j++) sum[j]=0;
            f[i][i]=0;
            g[i][i]=1;
            while(!q.empty()) q.pop();
            q.push({0,i,1});
            sum[0]=1;
            for(int j=i+1;j<=n;j++)
            {
                if(!q.empty())
                {
                    while(!q.empty()&&dis(q.front().id,j)>d)
                    {
                        cnt[q.front().x]--;
                        sum[q.front().x]-=q.front().ways;
                        q.pop();
                        if(q.empty()) break;
                    }
                }
                if(q.empty()) break;
                int x=q.front().x;
                f[i][j]=x+1;
                g[i][j]=sum[x];
                sum[f[i][j]]+=g[i][j];
                if(g[i][j]==2) ans++;
                q.push({f[i][j],j,g[i][j]});
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) 
            {
                f[i][j]=1e18;
                g[i][j]=0;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
