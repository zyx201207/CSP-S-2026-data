#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,x,s[N];
bool check(int j,int i)
{
	int need=(i-j)*a[i];
	int now=s[i-1]-s[j-1];
	if(need-now<=m) return true;
	else return false;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid,i)) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
