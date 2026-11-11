#include<bits/stdc++.h>
using namespace std;
long long s[1000010],p[1000010],k[1000010];
int tmp(int x,int y){
	return x > y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+1+n,tmp);
	for (int i = 2;i <= n;i++)
	{
		p[i] = s[i-1] - s[i] + p[i-1];
		k[1] += p[i];
	}
	if (m >= k[1])
	{
		printf("%d",n);
		return 0;
	}
	for (int i = 2;i <= n;i++)
	{
		k[i] = k[i-1] - (s[i-1] - s[i]) * (n-i+1);
		if (m >= k[i])
		{
			printf("%d",n-i+1);
			break; 
		}
	}
	return 0;
}
