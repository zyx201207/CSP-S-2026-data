#include <bits/stdc++.h>

using namespace std;
//int n,a,ans;
//string s;
long long n,ans;
struct t{
	int a;
	char c;
} s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	for(int i=1,j=n;i<=j;)
	{
		if(s[i].c==s[j].c)
		{
			if(s[i].a>s[j].a)
			{
				s[i].a-=s[j].a;
				j--;
			}
			else if(s[j].a>s[i].a)
			{
				s[j].a-=s[i].a;
				i++;
			}
			else
			{
				i++,j--;
			}
		}
		else
		{
			if(s[i].a>s[j].a)
			{
				s[i].a-=s[j].a;
				ans+=s[j].a;
				j--;
			}
			else if(s[j].a>s[i].a)
			{
				s[j].a-=s[i].a;
				ans+=s[i].a;
				i++;
			}
			else
			{
				ans+=s[j].a;
				i++,j--;
			}
		}
	}
	//for(int i=1;i<=n;i++)
	//{
	//	char c;
	//	cin>>a>>c;
	//	while(a--)
	//	{
	//		s+=c;
	//	}
	//}
	//for(int i=0;i<=int(s.size())/2;i++)
	//{
	//	if(s[i]!=s[s.size()-i-1])
	//	{
	//		ans++;
	//	}
	//}
	cout<<ans;
	return 0;
}
//Hello,Hello,Helloween!!! 
//Hello,Hello,Helloween!!! 
//Hello,Hello,Helloween!!! 
//Trick||Treat!
//Trick||Treat!
//Trick||Treat!
