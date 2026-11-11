#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long m,s[500010],a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m),l=1,r=n;
	for(int w=1;w<=n;w++)scanf("%lld",&a[w]);
	sort(a+1,a+n+1);
	for(int w=1;w<=n;w++)s[w]=s[w-1]+a[w];
	while(l<r){
		int mid=(l+r+1)/2,st=0;
		for(int w=mid;w<=n;w++)if(1ll*a[w]*mid-s[w]+s[w-mid]<=m)st=1;
		if(st)l=mid;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
