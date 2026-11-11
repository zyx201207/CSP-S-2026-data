#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=0x3f3f3f3f3f3f3f3f,eps=1e-8;
int a[N],pre[N];
int he(int l,int r){
	return pre[r]-pre[l-1];
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,ans=-inf;
	for(int r=1;r<=n;r++)
	{
		while(a[r]*(r-l+1)-he(l,r)>m&&l<=r) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}

