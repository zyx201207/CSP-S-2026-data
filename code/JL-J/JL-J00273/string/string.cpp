#include<bits/stdc++.h>
using namespace std;

long long f(string s,long long len);
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,len=0;
	string s="";
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long a;
		char ch;
		cin>>a>>ch;
		long long t=a;
		while(t--)
		{
			s+=ch;
			len++;
		}
	}
	cout<<f(s,len)<<endl;
	return 0;
}
long long f(string s,long long len)
{
	long long cnt=0;
	for(long long i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])cnt++;
	}
	return cnt;
}
