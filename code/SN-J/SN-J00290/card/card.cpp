#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int n,m;
int a[500005];
int mx[300005],mn[300005];
int ans[300005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(mx[a[i]]==0)
		{
			mx[a[i]]=i;
		}
		mn[a[i]]=i;
		for(int j=i;j<=n;j++)
		{
			ans[a[j]]++;
			if(mn[a[j]]!=mx[a[j]])
			{
				j=mx[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
