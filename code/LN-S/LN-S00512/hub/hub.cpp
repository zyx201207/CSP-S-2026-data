#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000010],d[1000010],shu[1000010],ans,fa[1000010][30],shen[1000010];
vector<int>v[1000010];
void dfss(int x,int y)
{
    shu[x]=1;
    for(int i = 0;i<v[x].size();i++)
    {
        if(v[x][i]==y)
            continue;
        if(c[v[x][i]]==1)
        {
            dfss(v[x][i],x);
        }
    }
}
void dfs1(int x,int y)
{
    shen[x]=shen[y]+1;
    fa[x][0]=y;
    for(int i = 0;i<v[x].size();i++)
    {
        if(v[x][i]==y)
            continue;
        dfs1(v[x][i],x);
    }
}
void init()
{
    for(int i = 1;i<=25;i++)
    {
        for(int j = 1;j<=a;j++)
        {
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}
int lca(int x,int y)
{
    if(shen[x]<shen[y])
        swap(x,y);
    for(int i = 25;i>=0;i--)
    {
        if(shen[fa[x][i]]>=shen[y])
            x=fa[x][i];
    }
    if(x==y)
        return x;
    for(int i = 25;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
int ju(int x,int y)
{
    return shen[x]+shen[y]-2*shen[lca(x,y)];
}
void dfs(int x,int y)
{
    if(x==a+1)
    {
        int dudu = 0;
        for(int i = 1;i<=a;i++)
        {
            shu[i]=0;
        }
        vector<int>v1,v2;
        for(int i = 1;i<=a;i++)
        {
            if(c[i]==1)
            {
                v1.push_back(i);
            }
            else
            {
                v2.push_back(i);
            }
            if(c[i]==1&&shu[i]==0&&dudu<=1)
            {
                dudu++;
                dfss(i,0);
            }
            else if(c[i]==1&&shu[i]==0&&dudu==2)
            {
                dudu=114514;
                break;
            }
        }
        if(dudu==114514)
            return ;
        int dvs = 0;
        for(int i = 0;i<v2.size();i++)
        {
            int sum = 1e9+7;
            for(int j = 0;j<v1.size();j++)
            {
                int sud = ju(v2[i],v1[j]);
                sum=min(sum,sud);
            }
            dvs=max(dvs,sum);
        }
        ans=min(ans,dvs);
        return ;
    }
    if(y!=b)
    {
        c[x]=1;
        dfs(x+1,y+1);
    }
    if(a-x+1+y>b)
    {
        c[x]=0;
        dfs(x+1,y);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int qwq,T;
    cin>>qwq>>T;
    while(T--)
    {
        ans=1e9+7;
        cin>>a>>b;
        for(int i = 1;i<=a;i++)
        {
            v[i].clear();
        }
        for(int i = 1;i<a;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs1(1,0);
        init();
        dfs(1,0);
        cout <<ans<<"\n";
    }
    return 0;
}
