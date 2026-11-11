#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=-1;
	for(int i=1;i<=n-m;i++)
	{
		int tot=a[i];
		for(int j=i+1;j<=m+i;j++)
		{
			tot and a[j];
		}
		ans=max(tot,ans);
	}
	cout<<ans;
	return 0;
} 
