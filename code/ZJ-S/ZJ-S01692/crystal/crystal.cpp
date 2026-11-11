#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long now=1,ans=1,nowx=a[1];
	for(int i=2;i<=n;i++){
		nowx+=a[i];
		now++;
		while(now>1&&now*a[i]-nowx>m) now--,nowx-=a[i-now];
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}
