#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
__int128 sum[N];
int n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=0;i--)
	{
		__int128 l=i*a[i]-sum[i];
		if(l<=m)
		{
			cout<<i;
			return 0;
		}
	}
}