#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,cnt=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		long long a;
		char c;
		scanf("%lld %c",&a,&c);
		for(int j=0;j<a;++j)
		{
			s+=c; 
		}
	}
	int len=s.size();
	if(len%2==0)
	{
		for(int i=1;i<=len/2;++i)
		{
			if(s[len/2-i]!=s[len/2+i-1])
			cnt++;
		}
		cout<<cnt-1;
	}
	else
	{
		for(int i=1;i<=len/2;++i)
		{
			if(s[len/2-i]!=s[len/2+i])
			cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
