#include <bits/stdc++.h>
using namespace std;
string s,x;
long long n,a,num,l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=0;i<n;i++)
	{
		cin>>a>>x;
		for (int j=0;j<a;j++)
		{
			s+=x;
		}
	}
	l=s.length();
	for (long long i=0;i<l/2+1;i++)
	{
		if (s[i]!=s[l-1-i])
		{
			s[l-1-i]=s[i];
			num++;
		}
	}
	cout<<num;
	return 0;
	
 } 
