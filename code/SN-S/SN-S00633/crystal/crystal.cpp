#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	long long a[100005];
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	int q=n/2;
	int x=a[q+1];
	int cnt=0;
	
	for(int i=q;i>0;i--)
	{
		if(x-a[i]<=m)
		{
			m-=(x-a[i]);
			a[i]=x;
		}
		else
		break;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x)
		cnt++;
	}
	
	cout<<cnt;
	return 0;
}
