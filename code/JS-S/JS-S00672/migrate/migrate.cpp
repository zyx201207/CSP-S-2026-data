#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define N 2000005
char rdc;
bool rdk;
ll rdx;
ll rd()
{
	rdx=rdk=0,rdc=getchar();
	while(rdc<'0'||rdc>'9')
	{
		if(rdc=='-')rdk=1;
		rdc=getchar();
	}
	while(rdc>='0'&&rdc<='9')
		rdx=(rdx<<1)+(rdx<<3)+(rdc^48),rdc=getchar();
	return rdk?-rdx:rdx;
}
int n;
ll x[N],d;
ll ans;
int bdy(long double f)
{
	int l=1,r=n,ret=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(f>=(long double)x[mid]-d)ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int dy(long double f)
{
	int l=1,r=n,ret=n+1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(f<(long double)x[mid]-d)ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
void sol_lyj()
{
	n=rd();
	d=rd();
	ans=0;
	for(int i=1;i<=n;i++)
		x[i]=rd();
	for(int i=1;i<n;i++)
	{
		int j=bdy(x[i]);
		if(j-i<2)continue;
		ans+=bdy(x[j-1])-dy(x[j-2])+1;
	}
	printf("%lld\n",ans);
}
int c,lyjkksk;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd();
	lyjkksk=rd();
	while(lyjkksk--)
		sol_lyj();
	return 0;
}
