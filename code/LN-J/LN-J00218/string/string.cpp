#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long s;
	char c;
}a[200010];
long long n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
	}
	long long s1=0,s2=0;
	for(int i=1,j=n;i<j;)
	{
		s1+=a[i].s;
		while(s2<s1)
		{
			if((s2+a[j].s)<=s1)
			{
				if(a[j].c!=a[i].c)
				{
					ans+=a[j].s;
				}
				s2+=a[j].s;
				a[j].s=0;
				j--;
			}
			else
			{
				if(a[j].c!=a[i].c)
				{
					ans+=(s1-s2);
				}
				a[j].s-=(s1-s2);
				s2=s1;
			}
		}
		i++;
	}
	cout<<ans;
	return 0;
}
