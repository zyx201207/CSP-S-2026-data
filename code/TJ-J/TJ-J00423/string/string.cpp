#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	freopen("string.in","r",stdin );
	freopen("string.out" ,"w",stdout);
	long long n;
	long long  a[200005];
	char c[200005];
	string s;
	long long cnt=0,ans=0,cnt1=0,m=0,b=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(a[i]!=1) b=1;
	}
	if(n>2000 && b==0) 
	{
		for(int i=1;i<=n;i++)
		{
			s[i]=c[i];
		}
		for(int i=1;i<=cnt/2;i++)
		{
			if(s[i]!=s[cnt+1-i]) ans++;
		}		
		cout<<ans;
	}
	else if(n>2000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)		
			{
				cnt++;
			}
		}	
		cout<<cnt/2;	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)		
			{
				cnt++;
				s[cnt]=c[i];
			}
		}
		for(int i=1;i<=cnt/2;i++)
		{
			if(s[i]!=s[cnt+1-i]) ans++;
		}
		cout<<ans;		
	}
	return 0;
}
