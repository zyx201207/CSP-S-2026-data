#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,d;
	int n,a,w=0;
	char c;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int q=1;q<=a;q++)
		{
			s[q+w]=c;
		}
		w=w+a;
		d[i-1]=c;
	}
	for(int e=1;e<=n;e++)
	{
		if(d[e-1]==d[e])
		{
			cout<<0;
			return 0;
		}
		if(s[e]!=s[w-e+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
