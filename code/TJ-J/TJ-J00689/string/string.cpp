#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
long long n,sum;
long long r(string a)
{
	if(a.size()%2==0) return a.size()/2+1;
	else return a.size()/2+1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long a;                                              
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++)
		{
			s=s+b;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s)
	{
		cout<<0;
		return 0;
	}
	for(long long i=s.size()-1;i>=r(s)-1;i--)
	{
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}
