#include<bits/stdc++.h>
using namespace std;
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s=s+c;
		}
	}
	int t=s.size();
	for(int i=s.size()-1;i>-1;i++)
	{
		b[i]=s[i];
	}
	cout<<s;
	if(t%2==0)
	{
		for(int i=0;i<t/2;i++)
		{
			if(s[i]!=b[i])
			{
				sum++;
			}
		}
	}
	else
	{
		for(int i=0;i<t/2+1;i++)
		{
			if(s[i]!=b[i])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
