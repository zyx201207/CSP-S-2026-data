#include<bits/stdc++.h>
using namespace std;
long long n,m,nax=0,a[200001],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(nax<a[i])nax=a[i];
		}
		cout<<nax;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]&a[j]>nax&&i!=j)nax=a[i]&a[j];
			}
		}
		cout<<nax;
		return 0;
	}
	return 0;
}
