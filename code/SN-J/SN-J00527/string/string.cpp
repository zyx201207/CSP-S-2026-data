#include <bits/stdc++.h>
using namespace std;
string s;
char c;
long long a,n,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	long long p=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=p;i<=p+a-1;i++)
		{
			s[i]=c;
		}
		p+=a;
	}
	if(p%2==0)
	{
		for(int i=1;i*2<=p-2;i++)
		{
			if(s[i]!=s[p-i])
			{
				sum++;
			}
		}
	}
	else
	{
		for(int i=1;i*2<=p-1;i++)
		{
			if(s[i]!=s[p-i])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
