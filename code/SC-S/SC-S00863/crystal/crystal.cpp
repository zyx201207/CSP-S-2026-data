#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],s[500005];
int n;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		long long sum;
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			sum=s[i]-s[mid-1];
			if(1LL*(i-mid+1)*a[i]-sum>m)
			l=mid+1;
			else
			r=mid-1;
		}
		ans=max(ans,i-l+1);
//		cout<<l<<" "<<i<<endl;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}