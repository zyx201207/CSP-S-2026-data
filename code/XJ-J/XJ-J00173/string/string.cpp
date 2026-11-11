#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
};
node s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,n;
	long long cnt=0,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	int flag=1;
	for(i=1;i<=n;i++)
	{
		if(!(s[i].c==s[n+1-i].c)) flag=0;
	}
	if(flag==1)
	{
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r)
	{
		cnt=0; 
		if(s[l].a==s[r].a)
		{
			if(s[l].c!=s[r].c)
			{
				cnt+=s[r].a;
				s[l].a=0;
				s[r].a=0;
				ans+=cnt;
			}
			else
			{
				s[l].a=0;
				s[r].a=0;
			}
		}
		else
		{
			if(s[l].c==s[r].c)
			{
				cnt+=abs(s[l].a-s[r].a);
				if(s[l].a>s[r].a)
				{
					s[l].a=cnt;
					s[r].a=0;
				}
				else
				{
					s[r].a=cnt;	
					s[l].a=0;		
				}
			}
			else
			{
				cnt+=min(s[l].a,s[r].a);
				if(s[l].a>s[r].a)
				{
					s[l].a=s[l].a-cnt;
					s[r].a=0;
				}
				else
				{
					s[r].a=s[r].a-cnt;	
					s[l].a=0;		
				}
				ans+=cnt;
			}
		}
		if(s[l].a==0) l++;
		if(s[r].a==0) r--;
	}
	cout<<ans;
	return 0;
}
