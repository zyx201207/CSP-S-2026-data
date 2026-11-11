#include<bits/stdc++.h>
using namespace std;
string a,b;
bool hwc(string d)
{
	bool x=1;
	for(int i=0;i<d.length()/2;i++)
	{
		if(d[i]!=d[d.length()-i-1])
		{
			x=0;
		}
	}
	return x;
} 
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		cin>>b;
		for(int j=1;j<=c;j++)
		{
			a=a+b;
		}
	}
	if(hwc(a))
	{
		cout<<0;
	}
	else
	{
		long long ans=0;
		for(int i=0;i<a.length()/2;i++)
		{
			if(a[i]!=a[a.length()-i-1])
			{
				a[a.length()-i]=a[i];
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
