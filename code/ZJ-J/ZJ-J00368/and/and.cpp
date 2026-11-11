#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,ans=(-1>>1);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=30;~i;i--)
	{
		int cnt=0;
		for(int j=0;j<n;j++)if(a[j]&(1<<i))b[cnt++]=a[j];
		if(cnt>=m)
		{
			n=cnt;
			for(int j=0;j<cnt;j++)a[j]=b[j];
		}
	}
	for(int i=0;i<n;i++)ans&=a[i];
	return cout<<ans,0;
}