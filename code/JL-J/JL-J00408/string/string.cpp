#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long s1=0;
	long long a;
	char b;
	string s2;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		s1+=a;
		s2+=b;
	}
	string s3;
	for(int i=n-1;i>=0;i--)
	{
		char k=s2[i];
		s3+=k;
	}
	if(s2==s3)
	{
		cout<<0;
	}
	else
	{
		long long q=s1/2;
		cout<<q;
	}
	return 0;
}
