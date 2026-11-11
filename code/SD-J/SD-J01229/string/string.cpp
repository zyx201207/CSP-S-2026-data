#include<bits/stdc++.h>
using namespace std;
int n,a;
string s,s1;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=0,jj=0,t=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		t+=a;
		for(j=jj;j<a+jj;j++)
		{
			s[j]=c;
		}
		jj=j;
	}
	for(int i=0;i<t;i++)
	{
		s1[t-i-1]=s[i];
	}
	long long sum=0;
	for(int i=0;i<t;i++)
	{
		if(s1[i]!=s[i])
			sum++;
	}
	cout<<sum/2;
	return 0;
} 
