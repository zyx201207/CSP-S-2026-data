#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];

int chk(int x)
{
	if(x>n)return 0;
	long long sum=0;
	for(int i=1;i<=x;i++)sum+=a[x]-a[i];
	if(sum<=m)return 1;
	for(int i=x+1;i<=n;i++)
	{
		sum-=a[i-1]-a[i-x];
		sum+=(a[i]-a[i-1])*(x-1);
		if(sum<=m)return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int k=(1<<19);k;k>>=1)
	if(chk(ans+k))ans+=k;
	cout<<ans;
	return 0;
}
