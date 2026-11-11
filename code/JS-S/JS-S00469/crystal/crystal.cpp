#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
int n,m;
ll a[N],sum[N];
bool check(int x)
{
     for(int i=x;i<=n;i++)
     {
         if(sum[i]-sum[i-x]+m>=(ll)x*a[i]) return 1;
     }
     return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
   cin>>n>>m;sum[0]=0;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+1+n);
   for(int i=1;i<=n;i++)
      sum[i]=sum[i-1]+a[i];
   int l=0,r=n;
   while(l<r)
   {
      int mid=(l+r+1ll)>>1;
      if(check(mid)) l=mid;
      else r=mid-1;
   }
   cout<<l;
   return 0;
}
