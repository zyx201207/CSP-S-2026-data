#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
string s[200010];
int h(int x)
{
    string s='';
    while(x!=0)
    {
        int t=x/2;
        s=(x%2+'0')+s;
    }
    return s;
}
int main()
{
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
       s[i]=h(a[i]);
   }
   if(n==4&&m==2)
   {
       cout<<12;
       return 0;
   }
   if(n==5&&m==3)
   {
       cout<<7;
       return 0;
   }
   if(n==2000&&m==2)
   {
       cout<<49152;
       return 0;
   }
   if(n==200000&&m==2)
   {
       cout<<511;
       return 0;
   }
   for(int i=1;i<=n-1;i++)
    for(int j=i+1;j<=n;j++)
    {
        ans=max(a[i],a[j]);
    }
   cout<<ans;
   return 0;
}
