#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],s1[500005],d,res,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) s1[i]=a[i]+s1[i-1];
	int l=1,r=1;
	while(r<=n)
	{
		d=r-l;
		res=a[r]*d-(s1[r-1]-s1[l-1]);
		if(res<=m)
		{
			ans=max(d+1,ans);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
