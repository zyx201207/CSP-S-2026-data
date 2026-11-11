#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   int n,m;
   cin>>n>>m;
   int a[n],b[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   int y,flag=0,flag2,ans,maxs=0;
   if(n%2!=0)
   {
       y=n/2+1;
   }
   else
   {
       y=n/2;
   }
   for(int i=0;i<n;i++)
   {
       maxs=a[n-1]-a[i];
   }
   if(m>=maxs)
   {
       ans=n;
   }
   while(m>0)
   {
       int cnt=0;
       for(int i=y;i<n;i++)
       {
           if(a[i]==a[y-1])
           {
               cnt++;
           }
       }
       if(flag2==n) break;
       for(int i=0;i<y;i++)
       {
           if(m>=a[y-1]-a[i])
           {
               m-=a[y-1]-a[i];
               cnt++;
               flag=1;
               flag2=i;
           }
       }
       if(flag==0) break;
       if(flag2=y-1 and m>0)
       {
           for(int j=y;j<n;j++)
        {
           if(m>=(a[j]-a[j-1])*j)
           {
               m-=(a[j]-a[j-1])*j;
               if(m>0)
               {
                   cnt++;
               }
               flag2=y;
           }
        }
       }
       ans=max(ans,cnt);
   }
   cout<<ans;
   return 0;
}
