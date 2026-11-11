#include<stdio.h>
#include<vector>
#include<algorithm>
#define M 1000005
using namespace std;
using ll=long long;
int n,p[M],q[M],cl[M],cr[M],c1[M],c2[M];
ll d,a[M];
vector<int> vp[M],vq[M];
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i) scanf("%lld",a+i),vp[i].clear(),vq[i].clear();
	for(int i=1,j=1;i<=n;++i){
		for(;a[i]-a[j]>d;++j);
		p[i]=j;
		if(p[i]<i) vp[p[i]].push_back(i);
	}
	for(int i=n,j=n;i;--i){
		for(;a[j]-a[i]>d;--j);
		q[i]=j;
		if(q[i]>i) vq[q[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		cl[i]=1;
		for(int x:vq[i]) if(x<i&&x>p[i]) ++cl[i];
		if(p[i]<i&&q[p[i]]==i) cl[i]+=cl[p[i]];
	}
	for(int i=n;i;--i){
		cr[i]=1;
		for(int x:vp[i]) if(x>i&&x<q[i]) ++cr[i];
		if(q[i]>i&&p[q[i]]==i) cr[i]+=cr[q[i]];
	}
	ll ans=0;
	for(int i=1;i<n;++i){
		ll a=0,b=0;
		for(int x:vp[i]) if(x>i+1&&x<q[i+1]) ++a;
		for(int x:vq[i+1]) if(x>p[i]&&x<i) ++b;
		if(p[i]<i&&q[p[i]]==i+1) b+=cl[p[i]];
		if(q[i+1]>i+1&&p[q[i+1]]==i) a+=cr[q[i+1]];
		ans+=a*b;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;scanf("%*d%d",&T);
	while(T--) solve();
}