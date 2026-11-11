#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005];//原数组，差分，差分的前缀和 
bool check(int x)
{
	//cout << x ;
	if(x==1) return true;
	long long dm=0;
	int start=n-x+1;
	for(int i=start+1;i<=n;i++)
	{
		dm+=(i-start)*b[i];
		//cout << 0 << ' ' << dm << ' ' ;
	}
	if(dm<=m) return true;
	for(int i=n-1;i>=x;i--)
	{
		dm-=(x-1)*b[i+1];
		start=i-x+1;
		dm+=(c[i]-c[start]);
		//cout << i << ' ' << dm << ' ' ;
		if(dm<=m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i]; 
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
		//cout << endl ;
		//cout << l << ' ' << r << endl ;
	}
	cout << l ;
	return 0;
}
