#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll n,m,a[N],s[N],l,r,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ans=1;
	for(l=1,r=1;r<=n;r++){
		while(l<=r&&a[r]*(r-l+1)-(s[r]-s[l-1])>m)
			l++;
		if(a[r]*(r-l+1)-(s[r]-s[l-1])<=m)
			ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}