#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int temp[200005];
int vis[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        int sum=0;
        for(int g=1;g<=n;g++)
        {
            int cnt=0;
            for(int j=1;j<=m;j++)
            {
                vis[j]=0;
            }
            for(int j=g;j<=n;j++)
            {
                if(vis[a[j]]==0)
                {
                    cnt++;
                    vis[a[j]]=cnt;
                }
                else
                {
                    for(int k=1;k<=m;k++)
                    {
                        if(vis[k]>vis[a[j]])
                        {
                            vis[k]=0;
                            cnt--;
                        }
                    }
                    cnt++;
                    vis[a[j]]=cnt;
                }
            }
            if(vis[i])sum++;
        }
        cout<<sum<<" ";
    }
    return 0;
}
