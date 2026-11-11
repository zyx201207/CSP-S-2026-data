#include <bits/stdc++.h>
using namespace std;
long long ans,sum;
struct h
{
	long long p;
	char a;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].p>>s[i].a;
		sum+=s[i].p;
	}
	long long mid=sum/2;
	int l=1,r=n;
	while(mid>0)
	{
		if(mid>=s[r].p)
		{
			if(s[l].p>s[r].p)
			{
				if(s[l].a!=s[r].a)
				{
					ans+=s[r].p;
				}
				mid-=s[r].p;
				s[l].p-=s[r].p;
				r--;
			}
			if(s[l].p==s[r].p)
			{
				if(s[l].a!=s[r].a)
				{
					ans+=s[r].p;
				}
				mid-=s[r].p;
				l++;r--;
			}
			if(s[l].p<s[r].p)
			{
				if(s[l].a!=s[r].a)
				{
					ans+=s[l].p;
				}
				mid-=s[l].p;
				s[r].p-=s[l].p;
				l++;
			}
		}
		else
		{
			long long x=s[r].p-mid;
			if(sum%2==0) x-1;
			mid-=x;
			if(mid>0) 
			{
				if(s[l].p>=mid&&s[l].a!=s[r].a) ans+=mid;
				if(s[l].p<mid)
				{
					for(int i=l;i<r;i++)
					{
						if(s[i].a==s[r].a) mid-=s[i].p;
					}
					ans+=mid;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
