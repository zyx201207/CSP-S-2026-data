#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],b[N];
int n,m;
int erfen(int l,int r,int i)
{
	if (l>=r) return l;
	int mid=(l+r)>>1;
	if ((b[i]-b[mid])-((mid-1)*(a[i]-a[mid]))<=m) return erfen(l,mid,i);
	else return erfen(mid+1,r,i);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int maxn=0;
	for (int i=1;i<=n;i++)
	{
		b[i]=(b[i-1]+(i-1)*(a[i]-a[i-1]));
		if (b[i]>m)
		{
			int l=erfen(1,i,i);
			maxn=max(maxn,i-l+1);
		 } 
		 else 
		 {
		 	maxn=max(maxn,i);
		 }
	}
	cout<<maxn;
	return 0;
}