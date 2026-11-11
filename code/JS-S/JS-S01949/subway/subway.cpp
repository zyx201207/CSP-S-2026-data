#include<bits/stdc++.h>
using namespace std;
long long numpath,dot,T,GunMu,GunMu2,x,y,fds,x1,x2;
int exitting[500005];
int pyth[505][500005];
long long tak[505][505];
queue<int> q[500005];
queue<int> q2[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>GunMu>>numpath>>dot>>GunMu>>T;
    for(int i=1;i<=dot;i++)
    {
        cin>>exitting[i];
    }
    for(int i=1;i<=numpath;i++)
    {
        cin>>GunMu;
        for(int j=1;j<=GunMu;j++)
        {
            cin>>GunMu2;
            q[GunMu2].push(i);
            q2[i].push(GunMu2);
            cin>>pyth[i][GunMu2];
        }
    }
    for(int i=1;i<=numpath;i++)
    {
        GunMu=q2[i].size();
        for(int j=1;j<=GunMu;j++)
        {
            x=q2[i].front();
            GunMu2=q[x].size();
            for(int qs=1;qs<=GunMu2;qs++)
            {
                y=q[x].front();
                fds=pyth[i][x]+pyth[y][x];
                if(tak[i][y]==0||fds<tak[i][y])
                {
                    tak[i][y]=fds;
                    tak[y][i]=fds;
                }
                q[x].pop();
                q[x].push(y);
            }
            q2[i].pop();
            q2[i].push(x);
        }
    }
    while(1)
    {
        bool flag=0;
        for(int i=1;i<=numpath;i++)
        {
            for(int j=1;j<=numpath;j++)
            {
                for(int qw=1;qw<=numpath;qw++)
                {
                    if(tak[qw][i]!=0&&tak[qw][j]!=0)
                    {
                        GunMu=tak[qw][i]+tak[qw][j];
                        if(tak[i][j]>GunMu||tak[i][j]==0)
                        {
                            tak[i][j]=GunMu;
                            tak[j][i]=GunMu;
                            flag=1;
                        }
                    }
                }
            }
        }
        if(!flag)
        {
            break;
        }
    }
    for(int i=1;i<=numpath;i++)
    {
        tak[i][i]=0;
    }
    long long ans;
    for(int i=1;i<=T;i++)
    {
        cin>>x>>y;
        GunMu=q[x].size();
        GunMu2=q[y].size();
        ans=tak[q[x].front()][q[y].front()]+pyth[q[x].front()][x]+pyth[q[y].front()][y];
        for(int ht=1;ht<=GunMu;ht++)
        {
            x1=q[x].front();
            for(int j=1;j<=GunMu2;j++)
            {
                x2=q[y].front();
                fds=tak[x1][x2]+pyth[x1][x]+pyth[x2][y];
                if(ans>fds)
                {
                    ans=fds;
                }
                q[y].pop();
                q[y].push(x2);
            }
            q[x].pop();
            q[x].push(x1);
        }
        ans+=exitting[x];
        ans+=exitting[y];
        cout<<ans<<endl;
    }
    return 0;
}
