#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[10000005];
LL rjz(int a)
{
	LL x = 0; LL cnt = 0;
	while(a)
	{
		if(x == 0 && a%2 == 0 && a != 0) cnt++;
		x = a%2 + x*10;
		a/=2;
	}
	LL s = 0;
	while(x)
	{
		s = s*10 + x%10;
		x/=10;
	}
	for(LL i = 1;i <= cnt;i++) 
	{
		s *= 10;
	}
	return s;
}
LL frjz(LL a)
{
	LL s = 0,w = 1;
	while(a)
	{
		s += (a%10)*w;
		w *= 2;
		a /= 10;
	}
	return s;
}
LL ad(LL a,LL b)
{
	int c = 0;
	while (max(a,b))
	{
		if(a%10 == b%10 && a%10 == 1) c = c*10+1;
		else c = c * 10;
		a /= 10;b /= 10;
	}
	return c;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	LL n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] = rjz(a[i]);
	}
	if(m == 1) 
	{
		cout<<"0";
		return 0;
	}
	if(m == n)
	{
		int ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans = ad(ans,a[i]);
		}
		cout<<frjz(ans);
		return 0;
	}
	LL mx = -1;
	for(int i = 1; i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(i != j)
			{
				mx = max(mx,ad(a[i],a[j]));
			}
		}
	}
	cout<<frjz(mx);
	return 0;
}
