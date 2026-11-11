#include <bits/stdc++.h>
using namespace std;
long long n,sum,cnt;
struct node
{
	int a;
	string b;
}s[200005];
bool tf=true;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
		sum+=s[i].a;
		if(i==1)continue;
		else 
			if(s[i].b!=s[i-1].b)tf=false;
	}
	if(tf)
	{
		cout<<0;
		return 0;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	long long ans=sum/2,r=n;
	long long ans1=ans;
	
	for(int i=1;i<=n;i++)
	{
		if(cnt>=ans1)break;
		if(s[i].a>=s[r].a&&cnt+s[r].a<=ans1)
		{
			s[i].a-=s[r].a;
			r--;
		}
		if(s[r].a>s[i].a&&cnt+s[i].a<=ans1)
		{
			s[r].a-=s[i].a;
			
		}
		if(cnt+min(s[i].a,s[r].a)>ans1)
		{
			if(s[i].b==s[r].b)ans-=ans1-cnt;
			break;
		}
		if(s[i].b==s[r].b)ans-=min(s[i].a,s[r].a);
		cnt+=min(s[i].a,s[r].a);
	}
	cout<<ans;
	
	
	
	
	return 0;
}
