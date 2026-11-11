#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
bool flag1=true,flag2=true;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ll n,m,d;
	scanf("%lld%lld", &n, &m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld", &a[i]);
		if(a[i]!=i)flag1=false;
		if(i==1)continue;
		if(i==2)d=a[2]-a[1];
		else if(d!=a[i]-a[i-1])flag2=false;
	}
	if(flag1)
	{
		ll ans=0,i=0;
		while(ans<=m)
		{
			ans+=i;
			i++;
		}
		printf("%lld", i-1);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(flag2)
	{
		ll ans=0,i=0,k=0;
		while(ans<=m)
		{
			ans+=i;
			i+=d;
			k++;
		}
		printf("%lld", k-1);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ll ans=0;
		for(int j=1;j<i;j++)
		{
			ans+=a[i]-a[j];
		}
		if(ans>m)
		{
			printf("%d", i-1);
			fclose(stdin);
			fclose(stdout);
			return 0; 
		}
	}
	
	printf("%lld", n);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
