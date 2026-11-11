#include <bits/stdc++.h>
using namespace std;

int n,ans;
long long m;
int a[500005];

int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int mid;
	mid=n/2+1;
	int l=1,r=n;
	for (int i=1;i<=r;i++)
	{
		if (a[mid]>a[l]) l++;
		else if (a[mid]==a[l]) break;
	}
	for (int i=1;i<=r;i++)
	{
		if (a[mid]<a[r]) r--;
		else if (a[r]==a[mid]) break;
	}
	int ii=l-1;
	ans+=r-l+1;
	int mi=m;
	while (mi>=0)
	{
		if (a[l]-a[ii]<=mi) 
		{
			ans++;
			mi-=a[l]-a[ii];
			ii--;
		}
		
		else if (ii==0 && (r*(a[r+1]-a[r]))<=mi)
		{
			ans++;
			mi-=r*(a[r+1]-a[r]);
			r++;
		}
		
		else mi=-1;
	}
	cout << ans;
	return 0;
}
