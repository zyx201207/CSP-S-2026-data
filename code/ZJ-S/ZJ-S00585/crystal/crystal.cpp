#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool check(int k)
{
	int cnt=0;
	for (int i=1;i<=k;i++) cnt+=(a[k]-a[i]);
	if (cnt<=m) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)&&l!=mid) l=mid;
		else r=mid-1;
	}
	if (check(n)) l=n;
	cout<<l;
	return 0;
}
