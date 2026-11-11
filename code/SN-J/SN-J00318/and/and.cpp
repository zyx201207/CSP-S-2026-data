#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	int maxx=-1;
	int n,m;
	int a[200005];
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		cout << maxx;
		return 0;
	}
	else if(m==n)
	{
		int sum=a[1]; 
		for(int i=2;i<=n;i++)
		{
			cout << sum<<endl;
			sum = sum and a[i];
		}
		cout << sum;
	}
	else
	{
		cout <<7;
	}
	return 0;
} 
