#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000006];
int ge[10][10][1000];
void dfs(int s,int y,int d,int dis,int n)
{
    if(y==n+1)
    {
        return;
    }
    for(int i=y+1;i<=n;i++)
    {
        if(x[i]-x[y]<=d)
        {
            ge[s][i][dis+1]++;
            dfs(s,i,d,dis+1,n);
        }
        else
        {
            break;
        }
    }
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)dfs(i,i,d,0,n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    sum+=max(0,(ge[i][j][k]*(ge[i][j][k]-1)/2));
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
