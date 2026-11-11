//SN-S00402 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
int s[500010];
int ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int x=a[1];
	for(int i=1;i<=n;i++) a[i]-=x;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=0;
	while(r<n)
	{
		while(r<n && m>=a[r+1]*(r+1-l+1)-(s[r+1]-s[l-1])) r++;
		ans=max(ans,r-l+1);
		l++;
	}
	cout<<ans;
	return 0;
}
