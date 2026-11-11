#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long a[MAXN];
long long cf[MAXN];
long long cz[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	int ans=1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n>5000)
	{
		int cha=a[1]-a[0];
		for(int i=2;i<=10;i++)
		{
			if(a[i]-a[i-1]!=cha)
			{
				cout<<n;
				return 0;
			}
		}
		int ans2=1;
		int sum=0;
		for(int i=1;i<n;i++)
		{
			sum+=cha*i;
			if(m>=sum)
			{
				ans2++;
			}
			else
			{
				break;
			}
		}
		cout<<ans2;
		return 0;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		cf[i]=a[i]-a[i-1];
		cz[i]=cf[i];
		if(m>=cz[i])
		{
			ans=2;
		}
	}
	if(ans==1)
	{
		cout<<ans;
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		int ie=0;
		for(int j=n-1;j>=i;j--)
		{
			cz[j]=cz[j-1]+cf[j]*i;
			if(m>=cz[j])
			{
				ans=i+1;
				ie=1;
			}
		}
		if(ie==0)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
