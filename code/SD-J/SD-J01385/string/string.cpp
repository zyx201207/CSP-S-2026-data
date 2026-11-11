#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;

struct STRING
{
	int cnt;
	char cha;
}str[N];

int n;
string s;
string revs;

signed main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	
	if(n==1)
	{
		printf("0");
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&str[i].cnt);
		str[i].cha=getchar();
		for(int i=1;i<=str[i].cnt;i++)
		{
			s+=str[i].cha;
		}
	}
	
	if(s.size()==1)
	{
		printf("0");
		return 0;
	}
	if(s.size()==2)
	{
		if(s[0]==s[1])
		{
			printf("0");
			return 0;
		}
		printf("1");
		return 0;
	}
	if(s.size()==3)
	{
		if(s[0]==s[2])
		{
			printf("0");
			return 0;
		}
		printf("1");
		return 0;
	}
	if(s.size()==4)
	{
		if(s[0]==s[3])
		{
			if(s[1]==s[2])
			{
				printf("0");
				return 0;
			}
			printf("1");
			return 0;
		}
		if(s[1]==s[2])
		{
			printf("1");
			return 0;
		}
		printf("2");
		return 0;
	}
	
	revs=s;
	reverse(revs.begin(),revs.end());
	if(revs==s) 
	{
		printf("0");
		return 0;
	}
	
	return 0;
}
