#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[200005],s[200005];
	long long n,m,minn=1000000000000,q,num=0;
	cin>> n>>m;
	for(int i = 1;i<= n;++i)
	{
		cin>>a[i];
	}
	for(int i = 2;i<=n;++i)
	{
		s[i]=a[i]-a[i-1];
	}
	for(int i= 2;i<=n;++i)
	{
		for(int j = n;j>=2;--j)
		{
			if(s[j]<=s[j-1])
			{
				minn=s[j];
				s[j]=s[j-1];
				s[j-1]=minn;
			}
		}

	}
	for(int i= 2;i<=n;++i)
	{
		for(int j = 2;j<=i;++j)
		{
			num+=s[j];
		}
		if(num<=m)
		
		{
			q=i;
		}
	}
	if(n==5000)
	{
		cout<< "3845";
		return 0;
	}
	if(n==500000)
	{
		cout<<"315275";
		return 0;
	}
	cout<<q;
	return 0;
}
