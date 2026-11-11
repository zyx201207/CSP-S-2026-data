#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long ans = 0;
struct node 
{
	long long a;
	char c;
} s[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	for (int i = 1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	for (int i = 1, j = n;i<j;)
	{
		
		if (s[i].c!=s[j].c)
		{
			if (s[i].a==s[j].a)
			{
				ans+=s[i].a, s[j].a-=s[i].a, s[i].a = 0;
				i++,j--;
			}
			else if (s[i].a<s[j].a)
			{
				ans+=s[i].a, s[j].a-=s[i].a, s[i].a = 0;
				i++;
			}
			else
			{
				ans+=s[j].a, s[i].a-=s[j].a, s[j].a = 0;
				j--;
			}
		}
		else
		{
			if (s[i].a==s[j].a)
			{
				s[j].a-=s[i].a, s[i].a = 0;
				i++,j--;
			}
			else if (s[i].a<s[j].a)
			{
				s[j].a-=s[i].a, s[i].a = 0;
				i++;
			}
			else
			{
				s[i].a-=s[j].a, s[j].a = 0;
				j--;
			}
		}
	}
	cout<<ans<<'\n';
	
	//²ÝÂÄ³æ²ÝÂÄ³æÑ»Ñ»Ï²»¶Äãß÷ 
	//£¨ËµÁËÒ»Ð©ÔÞÃÀµÄ»°£© 
	return 0;
}

