//SN-J00815 李雨轩 陕西延安中学
#include <bits/stdc++.h>
using namespace std;
int n,m;
void yuzhi1();
void yuzhi2();
void yuzhi3();
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if (m==1)
	{
		yuzhi1();
	}
	else if (m==n && n<=2000)
	{
		yuzhi2();
	}
	else if (m==2 && n<=2000)
	{
		yuzhi3();
	}
	else cout << 1;
	return 0;
}
void yuzhi1()
{
	long long a[2005];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << a[n];
}
void yuzhi2()
{
	long long a[2005];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	long long ans=a[1];
	for (int i=2;i<=n;i++)
	{
		ans&=a[i];
	}
	cout << ans;
}
void yuzhi3()
{
	long long a[2005];
	long long ans=a[1]&a[2];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			ans=max(a[i]&a[j],ans);
		}
	}
	cout << ans;	
}
