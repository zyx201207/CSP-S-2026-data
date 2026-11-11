#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
int a[N];
long long qzh[N];
int ans=0;
int m;
int check(int lo)
{
	long long sum=900000000000000007;
	for(int i=1;i+lo-1<=n;i++)
	{
		sum=min(sum,lo*a[i+lo-1]-(qzh[i+lo-1]-qzh[i-1]));
	}
	if(sum<=m) return 1;
	return 0;
}
void run()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+a[i];
	}
	int l=1;
	int r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)==1)
		{
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	run();
	return 0;
}