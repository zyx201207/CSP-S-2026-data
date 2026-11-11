#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int a[N],b[N],l[N],r[N],n,m,k,ans;
vector<int> vr[N],sl[N];
int solve(){
	puts("shu");
	for (int i=1;i<=n;++i){
		l[i]=lower_bound(a+1,a+n+1,a[i]-k)-a;
		r[i]=upper_bound(a+1,a+n+1,a[i]+k)-a-1;
	}
	int ans=0;
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j){
			int x=i,s=j-i,ct=1;
			while (x<j) s+=x,x=r[x],++ct;
			x=j;
			while (x>i) s-=x,x=l[x];
			if (s==1) ++ans;
		}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%*d%lld",&T);
	while (T--){
		scanf("%lld%lld",&m,&k),n=ans=0;
		if (m>300){
			for (int i=1,x;i<=m;++i)
				scanf("%lld",&x);
			puts("-1");
			continue;
		}
		for (int i=1,x;i<=m;++i){
			scanf("%lld",&x);
			if (n && x-a[n]>k) ans+=solve(),n=0;
			a[++n]=x;
		}
		ans+=solve();
		printf("%lld\n",ans);
	}
	return 0;
}