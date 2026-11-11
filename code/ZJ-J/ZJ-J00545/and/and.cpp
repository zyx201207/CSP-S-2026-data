#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans=pow(2,31)-1,a[N],maxn=0,k;
bool vis[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while (m--)
	{
		maxn=0;
		for (int i=1;i<=n;i++)
		{
		    if (ans&a[i]>maxn&&!vis[i])
		    {
		    	maxn=ans&a[i];
		    	k=i;
			}
		}
		vis[k]=1;
		ans=maxn;
	}
	cout<<ans;
	return 0;
}
