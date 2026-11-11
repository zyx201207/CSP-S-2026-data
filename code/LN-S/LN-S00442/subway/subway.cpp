#include<bits/stdc++.h>
using namespace std;
long long w[20010];
long long dis[510][510];
vector<int>eg[20510];
long long dep[20510];
bool vis[20510];
queue<int>q;
long long dis1[500010],dis2[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,Q,k,a,b,x,y,u,v;
    long long t,t2,mn,ans;
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        if(c>=7&&c<=11)
        {
            cin>>a>>t>>b>>t2;
            dis[a][b]=t+t2;
            dis[b][a]=t+t2;
        }
        else if(c>=12&&c<=15)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>a>>t;
                eg[a].push_back(m+i);
                eg[m+i].push_back(a);
            }
        }
        else if(n<=2)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>a>>t;
                if(i==1)dis1[a]=t;
                else dis2[a]=t;
            }
        }
        else
        {
            for(int j=1;j<=k;j++)
            {
                cin>>a>>t;
                dis[a][m+i]=t;
                dis[m+i][a]=t;
            }
        }
    }
    if(n<=2)
    {
        mn=dis[0][0];
        for(int i=1;i<=m;i++)
        {
            if(dis1[i]!=0&&dis2[i]!=0)
            {
                mn=min(mn,dis1[i]+dis2[i]);
            }
        }
        while(Q--)
        {
            cin>>x>>y;
            if(n==1)ans=w[x]+w[y]+dis1[x]+dis1[y];
            else
            {
                ans=dis[0][0];
                if(dis1[x]!=0&&dis1[y]!=0)ans=min(ans,w[x]+w[y]+dis1[x]+dis1[y]);
                if(dis2[x]!=0&&dis2[y]!=0)ans=min(ans,w[x]+w[y]+dis2[x]+dis2[y]);
                if(dis1[x]!=0&&dis2[y]!=0&&mn!=dis1[0])ans=min(ans,w[x]+w[y]+dis1[x]+dis2[y]+mn);
                if(dis2[x]!=0&&dis1[y]!=0&&mn!=dis1[0])ans=min(ans,w[x]+w[y]+dis2[x]+dis1[y]+mn);
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    if(c>=12&&c<=15)
    {
        while(Q--)
        {
            for(int i=1;i<=n+m;i++)vis[i]=0;
            while(!q.empty())q.pop();
            cin>>x>>y;
            q.push(x);
            dep[x]=0;
            vis[x]=1;
            ans=-1;
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                for(int i=0;i<eg[u].size();i++)
                {
                    v=eg[u][i];
                    if(vis[v])continue;
                    dep[v]=dep[u]+1;
                    if(v==y)
                    {
                        ans=w[x]+w[y]+dep[v]*t;
                        break;
                    }
                    q.push(v);
                    vis[v]=1;
                }
                if(ans!=-1)break;
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    if(c>=7&&c<=11)x=m;
    else x=n+m;
    for(int l=1;l<=x;l++)
    {
        for(int i=1;i<=x;i++)
        {
            if(i==l||dis[i][l]==dis[0][0])continue;
            for(int j=1;j<=x;j++)
            {
                if(j==i||j==l||dis[l][j]==dis[0][0])continue;
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    while(Q--)
    {
        cin>>u>>v;
        ans=w[u]+w[v]+dis[u][v];
        cout<<ans<<"\n";
    }
    return 0;
}
