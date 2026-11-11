#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],now;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int b=1,ans=0,tmp=a[1];
	for(int i=1;i<=31;i++)b*=2;
	now=n;
	while(b!=0)
	{
		int cnt=0,qwq=ans+b;
		for(int i=1;i<=n;i++)
		{
			int gmk=a[i]&qwq;
			if(gmk==qwq)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=b;
		}
		b/=2;
	}
	cout<<ans;
	return 0;
}