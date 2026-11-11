#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n;LL m;
LL a[N],s[N];
bool check(int l,int r)
{
	if(a[r]*(r-l+1)-(s[r]-s[l-1])<=m)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	int ans=0;
	for(int l=1,r=1;r<=n;++r)
	{
		while(!check(l,r))l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
