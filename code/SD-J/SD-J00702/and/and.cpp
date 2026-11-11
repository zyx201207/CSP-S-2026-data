#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[35][210000],s[35],ss[35];
long long ans;
void f(int x)
{
	for(int i=0;i<=30;i++)
	{
		ss[i]=s[i];
		s[i]=0;
	}
	for(int i=x;i>=0;i--)
		if(ss[i]>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=b[i][0];j++)
			{
				int k=b[i][j];
				for(int j=30;k!=0;j--)
					if(k>=(1<<j))
					{
						k-=(1<<j);
						s[j]++;
					}
			}
			f(i-1);
			return;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	while(n--)
	{
		cin>>a;
		long long k=a;
		for(int j=30;k!=0;j--)
			if(k>=(1<<j))
			{
				k-=(1<<j);
				b[j][0]++;
				b[j][b[j][0]]=a;
			}
	}
	for(int i=30;i>=0;i--)
	{
		if(b[i][0]>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=b[i][0];j++)
			{
				int k=b[i][j];
				for(int j=30;k!=0;j--)
					if(k>=(1<<j))
					{
						k-=(1<<j);
						s[j]++;
					}
			}
			f(i-1);
			break;
		}
	}
	cout<<ans;
	return 0;
}
