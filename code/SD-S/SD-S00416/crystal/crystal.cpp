#include<bits/stdc++.h>
using namespace std;
const int MX=5e5;
long long n,m,z,mx=1,sum,a[MX+10],i,p;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	p=1;
	for(i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-p);
		while(sum>m)
		{
			sum-=a[i]-a[p];
			p++;
		}
		mx=max(mx,i-p+1);
	}
	cout<<mx<<'\n';
	return 0;
}
