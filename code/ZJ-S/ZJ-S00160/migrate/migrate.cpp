#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(ll &x)
{
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f^=1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	if(f)
	{
		x=-x;
	}
}
const int N=2e6+1000;
const ll inf=4e18+5e17+100;
ll testcase,T,n,d,a[N],b[N],c[N];
void solve()
{
	read(n);
	read(d);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
	}
	a[0]=-inf;
	a[n+1]=inf;
	for(int i=0;i<=n+1;i++)
	{
		b[i]=c[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int le=lower_bound(a,a+n+2,a[i]-d)-a,ri=min(i-1,(int)(lower_bound(a,a+n+2,a[i+1]-d)-a-1));
		if(le<=ri)
		{
			b[i]=ri-le+1+b[le];
		}
	}
	for(int i=n;i;i--)
	{
		int ri=upper_bound(a,a+n+2,a[i]+d)-a-1,le=max(i+1,(int)(upper_bound(a,a+n+2,a[i-1]+d)-a));
		//cerr<<"C "<<i<<" "<<le<<" "<<ri<<"\n";
		if(le<=ri)
		{
			c[i]=ri-le+1+c[ri];
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cerr<<b[i]<<" ";
	}
	cerr<<"\n";
	for(int i=1;i<=n;i++)
	{
		cerr<<c[i]<<" ";
	}
	cerr<<"\n";
	*/
	ll as=0;
	for(int i=1;i<n;i++)
	{
		//as+=1ll*c[i]*b[i+1];
		int lle=lower_bound(a,a+n+2,a[i+1]-d)-a,lri=min(i-1,(int)(lower_bound(a,a+n+2,a[i+2]-d)-a-1)),lban=lower_bound(a,a+n+2,a[i]-d)-a,rri=upper_bound(a,a+n+2,a[i]+d)-a-1,rle=max(i+1,(int)(upper_bound(a,a+n+2,a[i-1]+d)-a)),rban=upper_bound(a,a+n+2,a[i+1]+d)-a-1;
		if(lle<=lri&&rle<=rri)
		{
			as+=1ll*(lri-lle+1+(lle==lban?b[lle]:0))*(rri-rle+1+(rri==rban?c[rri]:0));
			//cerr<<"! "<<i<<" L "<<(lri-lle+1+(lle==lban?b[lle]:0))<<" R "<<(rri-rle+1+(rri==rban?c[rri]:0))<<" "<<lle<<" "<<lri<<" "<<lban<<" "<<rle<<" "<<rri<<" "<<rban<<"\n";
		}
	}
	printf("%lld\n",as);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(testcase);
	read(T);
	while(T--)
	{
		solve();
		//cerr<<"solve finished\n";
	}
	return 0;
}
