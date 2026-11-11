#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],maxn;
int minn=1e9;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
		if(a[i]<minn)
		{
			minn=a[i];
		}
		if(m==1&&i==n)
		{
			cout<<maxn;
		}
		else if(m==2&&i==n)
		{
			cout<<(maxn&minn);
		}
	}
	return 0;
}

