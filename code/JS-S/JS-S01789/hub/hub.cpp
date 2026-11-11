#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,len[1005][1005],ans;
vector<int> v[1005];
bool vis[1005],no[1005];
void dfs(int idx,int fa,int now)
{
    for(auto i:v[idx])
    {
        if(i==fa)
        {
            continue;
        }
        len[now][i]=len[now][idx]+1;
        dfs(i,idx,now);
    }
}
void check(int idx,int fa)
{
    vis[idx]=0;
    for(auto i:v[idx])
    {
        if(i==fa||vis[i]==0)
        {
            continue;
        }
        check(i,idx);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        ans=0x3f3f3f3f;
        memset(len,0,sizeof(len));
        cin >> n >> k;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i,0,i);
        }
        for(int i=0;i<(1<<n);i++)
        {
            int cnt=0;
            memset(vis,0,sizeof(vis));
            memset(no,0,sizeof(no));
            for(int j=1;j<=n;j++)
            {
                if((1<<(j-1))&i)
                {
                    cnt++;
                    vis[j]=1;
                    no[j]=1;
                }
            }
            if(cnt==k)
            {
                int dis[1005],tim=0,tmp=0;
                memset(dis,0x3f,sizeof(dis));
                for(int j=1;j<=n;j++)
                {
                    if(vis[j])
                    {
                        check(j,0);
                        tim++;
                    }
                }
                if(tim<=2)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(no[j])
                        {
                            for(int l=1;l<=n;l++)
                            {
                                dis[l]=min(dis[l],len[j][l]);
                            }
                        }
                    }
                    for(int j=1;j<=n;j++)
                    {
                        tmp=max(tmp,dis[j]);
                    }
                    ans=min(ans,tmp);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            v[j].clear();
        }
        cout << ans << '\n';
    }
    return 0;
}
