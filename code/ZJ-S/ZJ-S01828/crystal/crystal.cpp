#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[510000],len,l,r,ans,maxn;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=r=1;
	while(l<=r&&r<=n)
	{
		len=r-l+1;
		if(ans<=m)
		{
			r++;
			ans=ans+len*(a[r]-a[r-1]);
			maxn=max(maxn,len);
		}
		else 
		{
			ans=ans-(a[r]-a[l]);
			l++;
		}
	}
	cout<<maxn;
	return 0;
}
