#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200009];
int u[10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll mx=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
		if(i==1) tot=a[i];
		else tot=(tot&a[i]);
	}
	if(m==1)
	{
		printf("%lld",mx);
		return 0;
	}
	if(m==n)
	{
		printf("%lld",tot);
		return 0;
	}
	if(mx<4)
	{
		for(int i=1;i<=n;i++)
		{
			u[a[i]]++;
		}
		if(u[3]>=m) printf("3");
		else if(u[3]+u[2]>=m) printf("2");
		else if(u[3]+u[1]>=m) printf("1");
		else printf("0");
		return 0;
	}
	if(m==2)
	{
		ll mix=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(i!=j) mix=max(mix,(a[i]&a[j]));
		printf("%lld",mix);
		return 0;
	}
	sort(a+1,a+n+1);
	ll maxn=0;
	for(int i=1;i<=n-m+1;i++)
	{
		int d=(a[i]&a[i+1]);
		maxn=max(maxn,(a[i+2]&d));
	}
	printf("%lld",maxn);
	
	
	return 0;
}
