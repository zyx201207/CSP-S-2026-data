#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=5e5+5;
int n;
ll m,a[N];
signed main()
{
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ll cur=0;
	int ans=0;
	for(int i=1,j=0;i<=n;i++){
		while(j<n&&cur+(j-i+1)*(a[j+1]-a[j])<=m)cur+=(j-i+1)*(a[j+1]-a[j]),j++;
		ans=max(ans,j-i+1);
		cur-=a[j]-a[i];
	}
	printf("%d",ans);
	return 0;
}