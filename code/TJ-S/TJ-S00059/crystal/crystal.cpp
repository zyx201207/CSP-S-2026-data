#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],c[50005][50005],maxx,ans,l,r;
int main()
{
	//========================================================
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			c[i][j]=a[j]-a[i];
		}
	}
	for(long long i=2;i<=n;i++)
	{
		l=1;
		maxx=0;
		for(long long j=1;j<i;j++)
		{
			maxx+=c[j][i];
			if(maxx>m)
			{
				maxx-=c[i][l];
				l++;
			}
			else
			{
				ans=max(ans,j-l+1);
			}
		}
	}
	cout << ans+1;
	return 0;
}//我尽力了，CSP-S，明年再战！ 
