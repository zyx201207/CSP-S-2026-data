#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
#define int long long
int a[maxn];
int sum[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	int l=1;
	for(int r=2;r<=n;r++)
	{
		while((r-l)*a[r]-(sum[r-1]-sum[l-1])>m)
		{
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
//	int ans=1;
//	for(int i=2;i<=n;i++)
//	{
//		int w=a[i]*(i-1)-sum[i-1];
//		if(w>m)
//		{
//			break;
//		}
//		else
//		{
//			ans++;
//		}
//	}
//	cout<<ans<<endl;
	return 0;
 } 
/*
5 8
-3 -1 2 2 7
*/
