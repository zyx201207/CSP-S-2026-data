#include<bits/stdc++.h>
using namespace std;
int arr[200001];
int abc(int a)
{
	long long b = 0;
	int o =1;
	while(a!=0)
	{
		int c = a%2;
		b+=c*o;
		o*=10;
		a/=2;
	}
	return b;
}
int abc1(long a,long b)
{
	long long c=0;
	int o = 1;
	while(a!=0&&b!=0)
	{
		int x = a%10;
		int y = b%10;
		a/=10;
		b/=10;
		if(x==1&&y==1)
		{
			c+=o;
		}
		o*=10;
	}
	return c;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i =0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	if(m==1)
	{
		cout << arr[n-1];
		return 0;
	}
	long long ans = abc(arr[n-1]);
	for(int i =n-1;i>=n-m;i--)
	{
		long long a;
		a = abc(arr[i]);
		ans = abc1(a,ans);
	}
	int cnt =0;
	int u = 1;
	while(ans!=0)
	{
		int x = ans%10;
		ans/=10;
		cnt+=x*u;
		u*=2;
	}
	cout << cnt;
	return 0;
} 
