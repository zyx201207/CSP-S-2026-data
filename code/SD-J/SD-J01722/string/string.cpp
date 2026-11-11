#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long l=0,r=s.length()-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			s[l]=s[r];
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
} 
