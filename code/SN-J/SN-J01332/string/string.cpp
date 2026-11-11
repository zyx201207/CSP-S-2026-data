#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long sum=0;
long long e=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	if(n==0 || n==1) 
	{
		cout<<0;
		return 0;
	}
	
	for(int i = 1;i<=n;i++)
	{
		long long x;
		char c;
		cin>>x>>c;
		for(int j = 1;j<=x;j++)
		{
			s+=c;
			e++;
		}
	}
//	cout<<s; 
	int f =1;
	for(int i = 1;i<e;i++)
	{
		if(s[i]!=s[0]) f=0;
	} 
	if(f==1) 
	{
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=e;i++)
	{
		long long si=s[e+1-i];
		if(s[i]!=si)
		{
			sum++;
		} 
	}
	cout<<e-sum+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
2
1000000000 a
1000000000 b


*/
