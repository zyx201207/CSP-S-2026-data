#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=1;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int z=1,nw=0;
	for(int i=2;i<=n;i++)
	{
		nw+=(i-z)*(a[i]-a[i-1]);
		while(nw>m)
		{
			nw-=a[i]-a[z];
			z++;
		}
		ans=max(ans,i-z+1);
	}
	cout<<ans<<'\n';
	return 0; 
}
