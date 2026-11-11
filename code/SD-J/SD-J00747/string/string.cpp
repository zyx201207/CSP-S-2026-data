#include<bits/stdc++.h>
using namespace std;
struct str
{
	long long a;
	char c;
}s[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	bool b=1;
	char c1;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		c1=s[1].c;
		if(s[i].c!=c1)
		{
			b=0;
		}
	}
	if(b)
	{
		cout<<0<<endl;
		return 0;
	}
	long long l=1,r=n;
	while(l<=r)
	{
		if(s[l].a==0)
		{
			l++;
			continue;
		}
		if(s[r].a==0)
		{
			r--;
			continue;
		}
		if(s[l].c!=s[r].c)
		{
			int c=s[l].a,d=s[r].a;
			ans+=min(c,d);
			s[l].a-=min(c,d);
			s[r].a-=min(c,d);
		}
		else if(s[l].c==s[r].c&&s[l].a!=s[r].a)
		{
			int c=s[l].a,d=s[r].a;
			s[l].a-=min(c,d);
			s[r].a-=min(c,d);
		}
		else
		{
			l++;
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
