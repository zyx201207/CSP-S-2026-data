#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,minm,x[501];
struct subway
{
    int grndis,isvisit;
    vector<int> pre,nxt,line,platdis;
}a[500001];
void dfs(int now,int fin,int nowline,int nowdis)
{
    int y;
    for(int i=0;i<a[now].line.size();i++)
    {
        if(a[now].line[i]==nowline)
        {
            y=i;
            break;
        }
    }
    if(now==fin)
    {
        minm=min(minm,nowdis+a[fin].platdis[y]+a[fin].grndis);
        return;
    }
    for(int i=0;i<a[now].line.size();i++)
    {
        if(a[now].pre[i]!=0&&a[a[now].pre[i]].isvisit==0)
        {
            a[a[now].pre[i]].isvisit=1;
            if(i!=y)
            {
                dfs(a[now].pre[i],fin,a[now].line[i],nowdis+a[now].platdis[i]+a[now].platdis[y]);
            }
            else
            {
                dfs(a[now].pre[i],fin,a[now].line[i],nowdis);
            }
            a[a[now].pre[i]].isvisit=0;
        }
        if(a[now].nxt[i]!=0&&a[a[now].nxt[i]].isvisit==0)
        {
            a[a[now].nxt[i]].isvisit=1;
            if(i!=y)
            {
                dfs(a[now].nxt[i],fin,a[now].line[i],nowdis+a[now].platdis[i]+a[now].platdis[y]);
            }
            else
            {
                dfs(a[now].nxt[i],fin,a[now].line[i],nowdis);
            }
            a[a[now].nxt[i]].isvisit=0;
        }
    }
    return;
}
void solve()
{
    int u,v;
    cin>>u>>v;
    for(int i=1;i<=m;i++)
    {
        a[i].isvisit=0;
    }
    a[u].isvisit=1;
    minm=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<a[u].line.size();i++)
    {
        dfs(u,v,a[u].line[i],a[u].grndis+a[u].platdis[i]);
    }
    cout<<minm<<endl;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].grndis;
        a[i].isvisit=0;
    }
    for(int i=1;i<=n;i++)
    {
        int p,y;
        cin>>p;
        for(int j=0;j<p;j++)
        {
            cin>>x[j]>>y;
            a[x[j]].platdis.push_back(y);
            a[x[j]].line.push_back(i);
        }
        for(int j=0;j<p-1;j++)
        {
            a[x[j]].nxt.push_back(x[j+1]);
            a[x[j+1]].pre.push_back(x[j]);
        }
        a[x[0]].pre.push_back(0);
        a[x[p-1]].nxt.push_back(0);
    }
    while(q--)
    {
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
