#include<bits/stdc++.h>
using namespace std;

struct cmpp
{
	long long d;
	char q;
};

long long n=0,ans=0;
cmpp s[200007];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long m=0;
		char a;
		cin>>m>>a;
		s[i].d=m;
		s[i].q=a;
	}
	
	long long j=n;
	long long x=0;
	long long y=0;
	for(long long i=1;i<=n;)
	{
		
		if(s[i].q!=s[j].q)
		{
			if(s[i].d==s[j].d)
			{
				ans=ans+s[j].d;
				s[i].d=0;
				s[j].d=0;
				i++;
				j--;
				continue;
			}
			if(s[i].d>s[j].d)
			{
				ans=ans+s[j].d;
				s[i].d=s[i].d-s[j].d;
				s[j].d=0;
				j--;
			}
			else
			{
				ans=ans+s[i].d;
				s[j].d=s[j].d-s[i].d;
				s[i].d=0;
				i++;
			}
		}
		else
		{
			if(s[i].d==s[j].d)
			{
				i++;
				j--;
				continue;
			}
			if(s[i].d>=s[j].d)
			{
				
				s[i].d=s[i].d-s[j].d;
				s[j].d=0;
				j--;
			}
			else
			{
				
				s[j].d=s[j].d-s[i].d;
				s[i].d=0;
				i++;
			}
		}
		if(i==j)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
	
}
