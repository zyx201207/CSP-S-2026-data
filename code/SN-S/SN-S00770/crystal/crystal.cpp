#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],pre[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0,l=1;
	for(int r=1;r<=n;r++){
		while(l<=r && (a[r]*(r-l+1)-(pre[r]-pre[l-1]))>m)l++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
