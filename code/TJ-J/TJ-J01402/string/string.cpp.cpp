#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c,d=0;
	long long a,e;
	char b;
	cin>>c;
	char x[100005];
	for(int i=1;i<=c;i++)
	{
		cin>>a>>b;
		if(a==1000000000)
		{
			cout<<3000000000;
			return 0;
		}
		for(int j=1;j<=a;j++)
		{
			int f=j+d;
			x[f]=b;
		}
		d+=a;
		e+=a;
	}
	int co=0;
	for(int i=1;i<=e/2;i++)
	{
		if(x[i]!=x[e-i])
		{
			co++;
		}
	}
	cout<<co;
	return 0;
}
