#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int maxn=1;
long long n,m,a[N],f[N];
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);	
  scanf("%lld%lld",&n,&m);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  sort(a+1,a+n+1);
  for(int i=2;i<=n;i++)
  {
     f[i]=(a[i]-a[i-1])*(i-1)+f[i-1];
     int l=1,r=i;
     while(l<=r)
     {
        int mid=(l+r)>>1;
        if(m>=(f[i]-f[mid]-(mid-1)*(a[i]-a[mid])))r=mid-1;
       else l=mid+1;
     }
     maxn=max(maxn,i-l+1);
  }
  printf("%d",maxn);
  return 0;
}
