#include<bits/stdc++.h>
using namespace std;
int n,m,vis[500005],s[300005];
int a[500005],l[300005],c[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            l[j]=0;
            c[j]=0;
        }
        for(int j=1;j<=n;j++)
        {
            vis[j]=0;
        }
        for(int j=i;j<=n;j++)
        {
            if(l[a[j]]!=0&&vis[l[a[j]]]==0)
            {
                for(int k=l[a[j]];k<=j-1;k++)
                {
                    vis[k]=1;
                }
            }
            l[a[j]]=j;
        }
        for(int j=i;j<=n;j++)
        {
            if(vis[j]==0)
            {
                if(c[a[j]]==0)
                {
                    s[a[j]]++;
                    c[a[i]]=1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}
