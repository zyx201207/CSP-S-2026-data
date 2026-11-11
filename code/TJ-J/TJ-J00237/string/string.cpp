#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	int g;
	cin>>n;
	string s1;
	string s2;
	string a[1000000001];
	long long l[1000000001];
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		cin>>g;
		cin>>a[i];
		for(int i=0;i<g;i++)
		{
		a[i]+=a[i];
		}
	} 
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=l[i];j++)
		{
			s[i]=s[i]+a[i];
		}
	}
	for(int i=0;i<n;i+=)
	{
		for(int j=n;j>=1;j--)
		{
			s2[i]+=a[i];
		}
	}
	if(s1==s2)
	{
		cout<<0<<endl;
	}
	else
	{
		string y=s1-s2;
	}
	cout<<y.length()<<endl;
	return 0;
}
