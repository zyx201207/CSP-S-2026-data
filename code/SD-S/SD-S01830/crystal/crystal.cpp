#include<bits/stdc++.h>
using namespace std;
long long a[500010],cf[500010],need[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cf[i]=a[i]-a[i-1],need[i]=need[i-1]+cf[i]*(i-1);
	long long ans=0,ip=1,jian=0;
	for(int i=1;i<=n;i++)
	{
		long long cnt=need[i]-jian;
		while(cnt>m)
		{
			ip++;
			jian+=cf[ip]*(ip-1);
			cnt-=cf[ip]*(ip-1);
		}
		ans=max(ans,i-ip+1);
	}
	cout<<ans;
	return 0;
}
