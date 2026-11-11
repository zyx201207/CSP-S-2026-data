#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2,j=1;i<=n;i++)
	{
		while((a[i]-a[i-1])*(i-j)>m-sum)
			sum-=a[i-1]-a[j++];
		sum+=(a[i]-a[i-1])*(i-j);
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

