//crystal
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,ans=1;
	long long sum=0;
	while(r<=n)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
		//cout<<l<<" "<<r<<" "<<sum<<"\n";
		while(sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		//cout<<l<<" "<<r<<" "<<sum<<"\n";
		r++;
	}
	cout<<ans;
	return 0;
}
