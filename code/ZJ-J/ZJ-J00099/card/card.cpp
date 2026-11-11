#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long pos[500005];
long long ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	  cin>>a[i];
	for(long long i=n;i>=1;i--)
	  if(pos[a[i]]==0) pos[a[i]]=i;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;)
		{
			ans[a[j]]++;
			if(pos[a[j]]!=j) j=pos[a[j]]+1;
			else j++;
		}
	}
	for(long long i=1;i<=m;i++)
	  cout<<ans[i]<<" ";
	return 0;
}
