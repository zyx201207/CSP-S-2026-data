#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0,ans=0;
map<char ,long long> m;
int  a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long x=sum/2;
	int i=1;
	while(x)
	{
		if(x>=a[i])
		{
			x-=a[i];
			m[c[i]]+=a[i];
			i++;
		}
		else if(x<a[i])
		{
			m[c[i]]+=x;
			a[i]-=x;
		}
	}
	a[i]-=bool(sum%2);
	x=sum/2;
	while(x)
	{
		if(x>=a[i])
		{
			x-=a[i];
			m[c[i]]+=a[i];
			i++;
		}
		else if(x<a[i])
		{
			m[c[i]]+=x;
		}
	}
	
	char l1;
	long long l2=0,ma=-1;
	bool f=1,ff=1;
	for(auto it:m)
	{
		if(it.second>ma)
		{
			ma=it.second;
		}
		if(f==1)
		{
			l1=it.first;
			l2=it.second;
			f=0;
		}
		else
		{
			if(it.first!=l1)
			{
				if(ff==1)
				{
					ans+=l2+it.second;
					ff=0;
				}
				else
				{
					ans+=it.second;
				}
			}
			l1=it.first;
			l2=it.second;
		}
	}
	if(ma>ans) cout<<ans;
	else cout<<ans-ma;
	
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

