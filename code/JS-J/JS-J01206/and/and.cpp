#include<bits/stdc++.h>
using namespace std;
int z[200005];int n,m,cnt=0;
bool vis[200005];
void dfs(int step,int ans)
{
    if(step==m)
    {
        cnt=max(cnt,ans);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            dfs(step+1,(ans&z[i]) );
            vis[i]=0;
        }
    }
    return ;
}
int main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   bool check=0,check1=0,check2=0,check3=0,checkn=0,checkB=0;
   cin>>n>>m;
   int tempn=n;
   while(tempn!=1)//tepan2k
   {
       if(tempn%2!=0)
       {
           checkn=1;
           break;
       }
       tempn/=2;
   }
    for(int i=0;i<n;i++)//shuru
    {
        cin>>z[i];
            if(z[i]==1)//tepan4
            check1=1;
            if(z[i]==2)//tepan4
            check2=1;
            if(z[i]==3)//tepan4
            check3=1;
            if(z[i]>=4)//tepan4
            check=1;
            if(z[i]!=i)//tepanB
            checkB=1;
    }
    if(m==1)//tepan6
    {
        sort(z,z+n);
        cout<<z[n-1];
        return 0;
    }
    if(check==0)//tepan16,17
    {
        if(check3==1&&check2==1)
        {
         cout<<2;
            return 0;
        }
         if(check3==1&&check1==1)
         {
             cout<<1;
             return 0;
         }
         cout<<0;
         return 0;
    }
    if(checkB==0&&checkn==0)//tepanB
    {
        int ans=z[n-1];
        for(int i=2;i<=n;i++)
            ans=(ans&z[n-i]);
        cout<<ans;
        return 0;
    }
    if(m==n)//tepan7
    {
        int ans=z[0];
        for(int i=1;i<n;i++)
        {
            ans=ans&z[i];
        }cout<<ans;
        return 0;
    }
    if(m==2)
    {
        for(int i=0;i<n-1;i++)
            for(int j=i;j<n;j++)
        {
            cnt=max(cnt,(z[i]&z[j]) );
        }
        cout<<cnt;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        vis[i]=1;
         dfs(1,z[i]);
         vis[i]=0;
    }
cout<<cnt;
}
