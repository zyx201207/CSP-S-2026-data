#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[200005];
int brr[200005];

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		brr[i]=arr[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int ans=arr[i];
		for(int j=1;j<=n;j++)
		{
			ans&=arr[j];
		
		}
		maxn=max(maxn,ans);
	}

	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

