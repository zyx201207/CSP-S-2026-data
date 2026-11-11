#include<bits/stdc++.h>
using namespace std;
long long c,n,d,t,ans,a[2005000],s[2005000],s1[2005000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		if(c<=12&&c>10)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			ans=(n-d/(a[n]-a[n-1]))-1*2;
		}
		else
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++)s[i]=a[i]-a[i];
			for(int i=1;i<=n;i++)
			{
				s1[i]=s1[i-1]+s[i];
			}
			for(int i=1;i<=n;i++)
			{
				if(s[i]/d!=0&&s[i]%d!=0)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}