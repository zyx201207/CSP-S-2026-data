#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
#define int long long
int n,m,a[maxn],s[maxn];
bool check(int mid)
{
	for(int i=1+mid-1;i<=n;i++)
	{
		int sum=a[i]*(mid-1)-(s[i-1]-s[i-mid]);
		if(sum<=m)return 1;
	}return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	//s[0]=a[1];
	int l=1,r=5e5;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
