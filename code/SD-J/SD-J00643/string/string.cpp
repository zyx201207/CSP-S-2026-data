#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
char c[100005];
unsigned long long sum=0;
string s;
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	bool flag1=true,flag2=true;
	for(int i=2;i<=n;i++)
	{
		if(c[i]!=c[i - 1]) flag1=false;
		if(a[i]!=a[i - 1]) flag2=false;
	}
	if(flag1==true) 
	{
	    cout<<0;
	    return 0;
	}
	if(flag2==true)
	{
		unsigned long long sum1=0;
		for(int i=1;i<=n/2;i++)
		{
			if(c[i]!=c[n+1 - i]) sum1+=a[i];
		}
		cout<<sum1;
		return 0;
	}  
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	long long x=s.length();
	for(long long i=0;i<x/2;i++)
		if(s[i]!=s[x - 1 - i]) sum++;
	cout<<sum;
	return 0;
 } 

