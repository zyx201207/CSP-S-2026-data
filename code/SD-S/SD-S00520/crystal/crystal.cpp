#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],pre[N],l,r,mid,ans;
bool check(int l,int r)
{
	int sum=pre[r]-pre[l-1];
	int need=a[r]*(r-l+1)-sum;
	return need<=m;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		l=1;
		r=i;
		while(l<r)
		{
			mid=(l+r)/2;
			if(check(mid,i))
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
