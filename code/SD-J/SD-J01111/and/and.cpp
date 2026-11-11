#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int num;
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		num=a[1];
		for (int i=2;i<=n;i++)
		{
			num=num&a[i];
		} 
		cout<<num;
		return 0;
	}
	int mx=0;
	if(m==2)
	{
		for(int i=1;i<=n-1;i++)
		{
			num=a[i]&a[i+1];
			if(num>mx)
			{
				mx=num;
			}
		}
		cout<<num;
	}
	return 0;
}
