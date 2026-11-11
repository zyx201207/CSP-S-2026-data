#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long int i,n,t,k,l,r,j,ans,ui;
struct node
{
	long long int a;
	char c;
}s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		t+=s[i].a;
	}
	i=1;
	j=n;
	while(1)
	{
		if((n%2==1&&i==j)||(n%2==0&&i>j))
		{
			cout<<ans;
			return 0;
		}
		if(s[i].a==s[j].a)
		{
			if(s[i].c!=s[j].c)
			{
				ans+=s[i].a;
				i++;
				j--;

			}
		}
		else
		{
			if(s[i].a<s[j].a)
			{
				if(s[i].c!=s[j].c)
				{
					ans+=s[i].a;
				}
				i++;
				s[j].a=s[j].a-s[i].a+1;

			}
			else
			if(s[i].a>s[j].a)
			{
				if(s[i].c!=s[j].c)
				{
					ans+=s[j].a;
				}
				j--;
				s[i].a=s[i].a-s[j].a+1;
			}
		}
	}
	return 0;
}