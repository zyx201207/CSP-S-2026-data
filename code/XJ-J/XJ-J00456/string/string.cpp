#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string q;
	long long n;
	cin>>n;
	long long a;
	char b;
	long long s=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>b;
		s+=a;
		q+=a*b;
	}
	s=s/2;
	long long p=0;
	for(long long i=0;i<s;i++)
	{
		if(q[i]!=q[s-i-1])
		{
			p++;
		}
	}
	cout<<p;
	return 0;
}

