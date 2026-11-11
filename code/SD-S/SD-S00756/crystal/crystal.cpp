#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500010],s[500010];
bool check (int l,int r) {
	if (a[r]*(r-l+1)-(s[r]-s[l-1])<=m) return 1;
	return 0;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=1;
	for (int i=1;i<=n;i++) {
		int l=i,r=n+1;
		while (l+1<r) {
			int M=(l+r)/2;
			if (check(i,M)) l=M;
			else r=M;
		}
		ans=max(ans,l-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
/*
14:50 ~ 14:57
！？惊天大水题？！ 
Oct31==Dec25?
*/
