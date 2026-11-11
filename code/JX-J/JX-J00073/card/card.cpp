#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=500010;
int n,m;
int a[N];
int stk[N],top;
int ans[N];
int last[N],fa[N];
vector<PII> e[N];
int head[N],ee[N],ne[N],idx;
bool used[N],vis[N];
int siz[N];
deque<int> q;
void add(int x,int y)
{
    ee[idx]=y,ne[idx]=head[x],head[x]=idx++;
}
bool check1()
{
    bool bb=true;
    for (int i=1;i<n;i++)
        bb&=(a[i]<=a[i+1]);
    return bb;
}
void bfs()
{
    while (q.size())q.pop_back();
    q.push_back(n);
    while (q.size())
    {
        int x=q.front();q.pop_front();
        if (vis[x])continue;
        vis[x]=true;
        for (int j=0;j<e[x].size();j++)
        {
            int y=e[x][j].first,z=e[x][j].second;
            if (vis[y])continue;
            fa[y]=x;
            if (z==1)q.push_back(y);
            else q.push_front(y);
        }
    }
}
void dfs(int x,int f)
{
    siz[x]=1;
    for (int i=head[x];i!=-1;i=ne[i])
    {
        int y=ee[i];
        if (y==f)continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    if (n<=5000)
    {
        for (int l=1;l<=n;l++)
        {
            top=0;
            for (int i=1;i<=m;i++)used[i]=false;
            for (int r=l;r<=n;r++)
            {
                if (used[a[r]])
                {
                    while (stk[top]!=a[r])
                    {
                        used[stk[top]]=false;
                        top--;
                    }
                }
                used[a[r]]=true;
                stk[++top]=a[r];
            }
            for (int i=1;i<=m;i++)
                if (used[i])
                    ans[i]++;
        }
        for (int i=1;i<=m;i++)cout<<ans[i]<<' ';
        cout<<endl;
        return 0;
    }
    if (check1())
    {
        for (int i=1;i<=n;i++)
            ans[a[i]]=max(ans[a[i]],i);
        for (int i=1;i<=m;i++)cout<<ans[i]<<' ';
        cout<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)last[a[i]]=i;
    for (int i=1;i<n;i++)
        if (last[a[i]]!=i)
        {
            e[last[a[i]]].push_back({i,0});
        }
    for (int i=1;i<n;i++)
        e[i+1].push_back({i,1});
    bfs();
    memset(head,0xff,sizeof (head));
    for (int i=1;i<n;i++)
        add(fa[i],i);
    dfs(n,-1);
    for (int i=1;i<=m;i++)
        cout<<siz[last[i]]<<' ';
    cout<<endl;
    return 0;
}