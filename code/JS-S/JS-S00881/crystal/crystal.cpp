#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N],ans=1,h,p=1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   scanf("%lld%lld",&n,&m);
   for(int i=1;i<=n;i++)
   {
       scanf("%lld",&a[i]);
   }
   sort(a+1,a+1+n,cmp);
   for(int i=1;i<=n;i++)
 {
       while(h<=m&&p<=n)
       {
           h+=a[i]-a[p];
           if(h<=m) ans=max(ans,p-i+1),p++;
           else break;
       }
       h-=(p-i+1)*(a[i]-a[i+1]);
   }
   printf("%lld",ans);
   return 0;
}
