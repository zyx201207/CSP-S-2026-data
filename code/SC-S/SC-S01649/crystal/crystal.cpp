#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],df[N],l,r,sum,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		df[i]=a[i]-a[i-1];
	}
	l=r=1;
	sum=0;
	while(r<=n)
	{
		while(r<=n&&sum<=m)
		{
			r++;
			sum+=df[r]*(r-l);
			ans=max(ans,r-l);
		}
		while(l<=r&&sum>m)
		{
			l++;
			sum-=a[r]-a[l-1];
		}
	}
	cout<<ans;
	return 0;
}