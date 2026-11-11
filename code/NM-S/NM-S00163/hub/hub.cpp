#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
bool dis[101][101];
int c,t;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[i][j]=0;
        }
        for(int i=1;i<n;i++)
        {
            int l,r;
            cin>>l>>r;
            dis[l][r]=dis[r][l]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(dis[j][k]>dis[j][i]+dis[i][k]&&dis[j][i]!=0&&dis[i][k]!=0)
                        dis[j][k]=dis[j][i]+dis[i][k];
                }
            }
        }
        priority_queue<int>aaa;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                aaa.push(dis[i][j]);
            }
        }
        for(int i=1;i<=k;i++)
            aaa.pop();
        cout<<aaa.top();
    }
    return 0;
}
