#include <bits/stdc++.h>
using namespace std;
long long n,a;
string s,c;
bool fun()
{
	for(int i=0;i<s.length();i++)
		if(!(s[i]==s[s.length()-i-1]))
			return false;
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{                                         
		cin>>a>>c;
		for(int j=0;j<a;j++) 
			s=s+c;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(fun())
	{
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=0;i<s.length();i++)
		if(!(s[i]==s[s.length()-i-1]))
			++cnt;
	cout<<cnt/2;
	return 0;
}
