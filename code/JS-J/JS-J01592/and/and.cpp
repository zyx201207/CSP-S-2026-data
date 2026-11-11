#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxbit=1,mask=1,maxn=0;
bool vis[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        a[i]=k;
        maxn=max(a[i],maxn);
    }
    maxbit=1,mask=2;
    for(int i=1;i<=30;i++)
    {
        maxbit*=2;
        mask*=2;
    }
    for(int i=30;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(a[j]%mask)/maxbit>=1)
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(!vis[j]&&(a[j]%mask)/maxbit==0)
                {
                    vis[j]=true;
                }
            }
        }
        mask/=2;
        maxbit/=2;
    }
    int cnt=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&cnt<m)
        {
            cnt++;
            if(cnt==1)
            {
                ans=a[i];
            }
            else
            {
                ans=ans&a[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
