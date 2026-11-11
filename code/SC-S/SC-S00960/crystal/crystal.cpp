#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,l,r) for(int i=(l),num##i=(r);i<=num##i;++i)
#define per(i,r,l) for(int i=(r),num##i=(l);i>=num##i;--i)
#define fileI(x) freopen(x,"r",stdin)
#define fileO(x) freopen(x,"w",stdout)
#define ML printf("\n.2lf MB\n",(&M2-&M1)/1024.0/1024)
#define TL printf("\n.2lf s\n",1.0*clock()/CLOCKS_PER_SEC)
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
bool M1;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
ll GetVal(int l,int r,ll ar){
	return 1LL*ar*(r-l+1)-(sum[r]-sum[l-1]);
}
bool M2;
int main(){
	fileI("crystal.in");
	fileO("crystal.out");
	scanf("%d%lld",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,n)sum[i]=sum[i-1]+a[i];
	for(int r=1,l=1;r<=n;++r){
		while(GetVal(l,r,a[r])>m)++l;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}