#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<bitset>
#define int long long
using namespace std;
int n,m;
int ans=0,s=0;
int a[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=a[i]&s;
		s|=a[i];
	}
	if(m==1) cout<<0;
	else if(m==n) cout<<ans;
	else if(m==2)
	{
		ans=0;
		int l=1;
		if(n>2000)
		{
			sort(a+1,a+n+1);
			l=n-2000;
		}
		for(int i=l;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else cout<<ans;
	return 0;
}
