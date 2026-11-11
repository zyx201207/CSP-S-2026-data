#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N 500005
int n;
ll a[N],m;
bool chk(int x)
{
  ll ts = 0,xg = 0;
  for(int i = 1;i <= n;i++)
  {
    if(i > x) ts -= a[i - x];
	ts += a[i];
	if(i >= x)
	{
	  xg = x * a[i] - ts;
      if(xg <= m) return 1;
	}
  }
  return 0;
}
int main()
{
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  scanf("%d%lld",&n,&m);
  for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
  sort(a + 1,a + 1 + n);
  int l = 0,r = n,mid;
  while(l <= r)
  {
  	mid = (l + r) / 2;
  	if(chk(mid)) l = mid + 1;
  	else r = mid - 1;
  }
  printf("%d",r);
  return 0;
}
