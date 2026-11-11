#include <bits/stdc++.h>
const int M=5e5+5;
long long a[M],s[M],s2[M];
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,ans=1;
	cin>>n>>m;
	s[0]=0;
	a[0]=0;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
	{
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		s2[i]=s2[i-1]+a[i];
		int i1=(upper_bound(s+1,s+i,s[i]-m))-s;

		auto it=upper_bound(s+1,s+i,s[i]-m);

		int i2=it-s;
		long long tmp=0;

		long long tmp1=s[i]-*(it)-(a[i]-a[it-s])*(it-s-1);
		long long l=1,r=i2,md=(l+r)/2,cost=(i-md+1)*a[i]-(s2[i]-s2[md-1]);
		if(i2!=0&&md!=0 && cost!=m)
		{
			while (l!=md)
			{
				if(cost>m)
				{
					l=md;
				}
				else if (cost<=m)
				{
					r=md;
				}
				md=(l+r)/2;
				cost=(i-md+1)*a[i]-(s2[i]-s2[md-1]);
			}
		}
		if(md==1)md--;
		ans=max(ans,i-md);
	}
	cout<<ans<<endl;
	return 0;
}
