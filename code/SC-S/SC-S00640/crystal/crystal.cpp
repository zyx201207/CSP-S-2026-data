#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;
long long n,m,a[N],pre[N];

int check(int k)
{
	for(int i=1;i+k-1<=n;i++)
	{
		int l=i,r=i+k-1;
		if((r-l)*a[r]-(pre[r-1]-pre[l-1])<=m) return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n,mid=-1,res=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<res;
	return 0;	
} 