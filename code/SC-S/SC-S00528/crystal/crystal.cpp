#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],cha[N];
signed main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	bool flag=1,flagx=1;
	cin>>a[1];
	if(a[1]!=1) flag=0;
	int la=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=i) flag=0;
		if(a[i]-a[i-1]!=la)
		{
			flagx=0;	
		}
		la=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	//rp++
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			int an=(1+i)*i/2;
			if(an>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	if(flagx)
	{
		for(int i=1;i<=n;i++)
		{
			int an=(1+i)*i/2;
			if(an*la>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	return 0;
}