#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,ans=1,k;
long long a[N],sum,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	k=1;
	sum=0;
	for(int i=2;i<=n;i++)
	{
		sum+=k*(a[i]-a[i-1]);
		k++;
		while(sum>m)
		{
			sum-=a[i]-a[i-k+1];
			k--;
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
