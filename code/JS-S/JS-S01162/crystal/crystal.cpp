#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const ll M=1e18+10;

int n;
ll m;
ll a[N],b[N];
inline int readi()
{
	char c;
	c=getchar();
	int x=0;
	int f=1;
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	while((c<='0' || c>='9' )&& c!=' ' && c!= '\n')
	{
		f=-1;
		c=getchar();
	}
	return f*x;
}
inline ll readl()
{
	char c;
	c=getchar();
	ll x=0;
	ll f=1;
	while(c=='-')
	{
		f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	
	return f*x;
}
bool cmp(ll a,ll b)
{
	return a>b;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=readi();
	m=readl();
//	scanf("%d%lld",&n,&m);
	if(n>5000)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=readl();
			scanf("%lld",&a[i]);
		}
		int i=2;
		while(i*(i+1)/2 <=n)i++;
		printf("%d\n",i);
	}
	else
	{
		
		for(int i=1;i<=n;i++)a[i]=readl();
		sort(a+1,a+n+1,cmp);
		ll ans=-1;
		
		for(int i=1;i<=n;i++)
		{
			int k=m;
			ll cnt=0;
			for(int j=i;j<=n;j++)
			{
				if(k >= (a[i]-a[j]))
				{ 
					cnt++;
					k -= (a[i]-a[j]);
				}
			}
//			printf("%lld\n",cnt);
			ans=max(cnt,ans);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
