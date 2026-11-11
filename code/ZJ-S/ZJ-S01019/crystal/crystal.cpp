#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+25;
int n,m;
int a[N];
int qjh[N];
int ans;
bool check(int x)
{
	for(int i=n;i>=x;i--)
	{
		int l=i-x+1;
		int cost=(i-l+1)*(a[i])-(qjh[i]-qjh[l-1]);
		if(cost<=m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qjh[i]=qjh[i-1]+a[i];
	}
	int L=1,R=n;
	int ans=1;
	while(L<=R)
	{
//		cout<<L<<" "<<R<<"\n";
		int mid=(L+R)>>1;
		if(check(mid))
		{
			ans=mid;
			L=mid+1;
		}
		else
		{
			R=mid-1;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			int cost=(j-i+1)*(a[j])-(qjh[j]-qjh[i-1]);
//			if(cost<=m)
//			{
//				ans=max(ans,(j-i+1));
//			}
//		}
//	}
	cout<<ans;
	return 0;
}
//5 5
//1 2 4 8 9