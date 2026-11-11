#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N=510,M=500010,n1=40010,m1=80010,INF=0x3f3f3f3f;
int ooo,n,m,d,qq,cnt;
int hav[M],ans[M];
int ad[M];
int head[n1],e[m1],w[m1],ne[m1],idx;
int dist[n1];
bool vis[n1];
struct Node
{
    int s,t,id;
}a[100010];
bool cmp(Node A,Node B)
{
    return A.s<B.s;
}
priority_queue<PII,vector<PII>,greater<PII>> q;
deque<int> q2;
void add(int x,int y,int z)
{
    e[idx]=y,w[idx]=z,ne[idx]=head[x],head[x]=idx++;
}
void dijkstra(int s)
{
    while (!q.empty())q.pop();
    for (int i=1;i<=cnt;i++)dist[i]=INF,vis[i]=false;
    q.push({0,s});
    dist[s]=0;
    while (!q.empty())
    {
        int x=q.top().second;q.pop();
        if (vis[x])continue;
        vis[x]=true;
        for (int i=head[x];i!=-1;i=ne[i])
        {
            int y=e[i];
            if (dist[y]>dist[x]+w[i])
            {
                dist[y]=dist[x]+w[i];
                q.push({dist[y],y});
            }
        }
    }
}
void bfs(int s)
{
    while (q2.size())q2.pop_front();
    for (int i=1;i<=cnt;i++)dist[i]=INF,vis[i]=false;
    q2.push_back(s);
    dist[s]=0;
    while (q2.size())
    {
        int x=q2.front();q2.pop_front();
        if (vis[x])continue;
        vis[x]=true;
        for (int i=head[x];i!=-1;i=ne[i])
        {
            int y=e[i];
            if (vis[y])continue;
            if (dist[y]>dist[x]+w[i])
            {
                dist[y]=dist[x]+w[i];
                if (!w[i])q2.push_front(y);
                else q2.push_back(y);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(head,0xff,sizeof (head));
    cin>>ooo>>n>>m>>d>>qq;cnt=m;
    for (int i=1;i<=m;i++)cin>>ad[i];
    for (int j=1;j<=n;j++)
    {
        int k,last;
        cin>>k;
        for (int i=1;i<=k;i++)
        {
            int a,t;
            cin>>a>>t;
            cnt++;
            add(a,cnt,t);add(cnt,a,t);
            if (i!=1)
            {
                add(last,cnt,0);
                add(cnt,last,0);
            }
            last=cnt;
        }
    }
    for (int i=1;i<=qq;i++)
    {
        int s,t;
        cin>>s>>t;
        a[i]={s,t,i};
        ans[i]=ad[s]+ad[t];
    }
    sort(a+1,a+qq+1,cmp);
    if (ooo<=11)
    {
        for (int i=1;i<=qq;)
        {
            int s=a[i].s,j=i;
            dijkstra(s);
            while (j<=qq&&a[j].s==s)
            {
                ans[a[j].id]+=dist[a[j].t];
                j++;
            }
            i=j;
        }
        for (int i=1;i<=qq;i++)
            cout<<ans[i]<<'\n';
        return 0;
    }
    for (int i=1;i<=qq;)
        {
            int s=a[i].s,j=i;
            bfs(s);
            while (j<=qq&&a[j].s==s)
            {
                ans[a[j].id]+=dist[a[j].t];
                j++;
            }
            i=j;
        }
    for (int i=1;i<=qq;i++)
        cout<<ans[i]<<'\n';
    return 0;
}