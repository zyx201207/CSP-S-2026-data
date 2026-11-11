#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=5e5+5;
int n,m,a[MAXN],pre[MAXN],ans=1;

int calc(int p)
{
	int L=1,R=p,ans=1;
	while(L<=R)
	{
		int mid=L+(R-L)/2;
		if(a[p]*mid-(pre[p]-pre[p-mid])<=m) ans=mid,L=mid+1;
		else R=mid-1;
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,calc(i));
	cout<<ans;
	return 0;
}
