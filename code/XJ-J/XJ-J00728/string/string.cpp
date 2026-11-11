#include<iostream>
using namespace std;
long long a[114514];
char b[114514];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0;
	double ans=0;
	cin>>n;
	string s;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		c++;
	} 
	for (int i=1;i<=c;i++)
	{
		for (int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}

	for (int i=0;i<=s.length();i++)
	{
		if (s[i]!=s[s.length()-i-1])
		{
			ans+=0.5;
		}
	}
	cout<<ans;
	return 0;
 } 
