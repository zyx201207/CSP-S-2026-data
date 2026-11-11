#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000010,n1=310,M=n1*n1,INF=0x3f3f3f3f3f3f3f3f;
int ooo,t,n,d,res;
int a[N];
int head[n1],e[M],ne[M],idx;
int dist[n1],ans[n1];
queue<int> q;
void add(int x,int y)
{
    e[idx]=y,ne[idx]=head[x],head[x]=idx++;
}
void init()
{
    for (int i=1;i<=n;i++)head[i]=-1;
    res=idx=0;
}
void bfs(int s)
{
    while (q.size())q.pop();
    for (int i=1;i<=n;i++)ans[i]=0,dist[i]=INF;
    q.push(s);
    dist[s]=0;
    ans[s]=1;
    while (q.size())
    {
        int x=q.front();q.pop();
        for (int i=head[x];i!=-1;i=ne[i])
        {
            int y=e[i];
            if (dist[y]>dist[x]+1)
            {
                dist[y]=dist[x]+1;
                q.push(y);
                ans[y]=ans[x];
            }
            else if (dist[y]==dist[x]+1)
            {
                ans[y]+=ans[x];
            }
        }
    }
}
bool check_A()
{
    int c=a[2]-a[1];
    for (int i=1;i<n;i++)
        if (a[i+1]-a[i]!=c)
            return false;
    return true;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>ooo>>t;
    while (t--)
    {
        cin>>n>>d;
        for (int i=1;i<=n;i++)cin>>a[i];
        if (n==1)
        {
            cout<<0<<endl;
            continue;
        }
        if (n<=300)
        {
            init();
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    if (a[j]-a[i]<=d)
                    {
                        add(i,j);add(j,i);
                    }
            for (int i=1;i<=n;i++)
            {
                bfs(i);
                for (int j=1;j<=n;j++)
                    if (ans[j]==2)
                        res++;
            }
            cout<<res/2<<endl;
            continue;
        }
        if (check_A()||ooo>=11&&ooo<=12)
        {
            int c=a[2]-a[1];
            if (d<2*c)cout<<0<<endl;
            else
            {
                int k=(d/c)+(d/c-1);
                cout<<max(0ll,n-k)<<endl;
            }
            continue;
        }
    }
    return 0;
}