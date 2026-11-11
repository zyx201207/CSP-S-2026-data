/*2.45done
»Æ 


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5;
int n,m;
int a[N],v[N],sum[N];

int calc(int l,int r)
{
	return a[r]*(r-l+1) - (sum[r]-sum[l-1]);
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int a1=a[1];
	int ans = 1;
	for(int i=1;i<=n;i++)
	{
		a[i]-=a1;
		sum[i] = sum[i-1] + a[i];
		int l=1,r=i;
		while(l < r)
		{
			int mid = l+r>>1;
			if(calc(mid,i) > m)	l=mid+1;
			else	r=mid;
		}
		ans = max(ans,i-l+1);
	}
	cout<<ans<<endl;
	
	return 0;
}
