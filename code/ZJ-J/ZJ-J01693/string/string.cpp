#include<bits/stdc++.h>
using namespace std;
char s[300000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,a,l = 0;
	char c;
	cin>>n;
	for(long long i = 1;i <= n;i++)
	{
		cin>>a>>c;
		for(long long j = l;j < l + a;j++)
		{
			s[j] = c;
		}
		l+=a;
	}
	bool f = 0;
	long long cnt = 0;
	for(long long i = 0;i < l/2;i++)
	{
		if(s[i] != s[l - i - 1]) 
		{
			cnt++;
			f = 1;
		}
	}
	if(f == 0)
	{
		cout<<"0";
	}
	else
	{
		cout<<cnt;
	}
	return 0;
}
