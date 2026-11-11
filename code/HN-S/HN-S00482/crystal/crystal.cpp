#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,l=1,sum=0,maxx=1,sl=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		sum+=(sl*(a[i]-a[i-1]));
		if(sum<=m)
		{
			maxx=max(maxx,sl+1);
			sl++;
		}
		else
		{
			while(sum>m)
			{
				sum-=(a[i]-a[l]);
				l++;
				sl--;
			}
		}
	}
	cout<<maxx;
	return 0;
}

