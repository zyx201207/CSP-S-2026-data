#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],f[N],b[N];
bool check(int k)
{
	for(int i=k;i<=n;i++)
	{
		int id=i-k+1;
		if(f[i]-f[id]-(id-1)*(a[i]-a[id])<=m)
			return true;
	}
	return false;
}
int find()
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))		l=mid;
		else				r=mid-1;
	}
	return l;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	cout<<find();
	return 0;
}