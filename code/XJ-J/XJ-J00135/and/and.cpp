#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],vis[200005];
long long ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int j=30;j>=0;j--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		if(vis[i]==0&&((a[i]>>j)&1))
		cnt++;
		if(cnt>=m)
		{
			ans+=(1<<j);
			for(int i=1;i<=n;i++)
			if(vis[i]==0&&(!((a[i]>>j)&1)))
			vis[i]=1;		
		}
	}
	cout<<ans;
	return 0;
}
