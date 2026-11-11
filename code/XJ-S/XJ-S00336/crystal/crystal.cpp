#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ii=1;
	long long ans=1,mm=m,cnt=1;
	for(int i=2;i<=n;i++)
	{
		cnt=i-ii;
		long long dj=cnt*(a[i]-a[i-1]);
		if(mm>=dj)
		{
			mm-=dj;
			cnt++;
			ans=max(ans,cnt);
		}
		else
		{
			ii++;
			cnt--;
			mm+=a[i-1]-a[ii]-cnt*(a[i]-a[i-1]);
		}
	}
	cout<<ans;
	return 0;
}
