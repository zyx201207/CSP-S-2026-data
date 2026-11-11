#include<bits/stdc++.h>
using namespace std;

typedef int itn;
const int N=200010;

itn main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(itn i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++)
		{
			s+=b;
		}
	}
	long long sum=0,len=s.size();
	for(long long i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])sum++;
	}
	cout<<sum;
	return 0;
}