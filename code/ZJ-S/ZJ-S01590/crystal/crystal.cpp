#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500002];
int fs[500002];
inline int get_sum(int l,int r){return fs[r]-fs[l-1];}
inline int get_len(int l,int r){return r-l+1;}
bool check(int p,int x){
	int l=p-x+1;
	return (x*a[p]-get_sum(l,p))<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	a[0]=-0x3f3f3f3f3f3f3f3f;
	a[n+1]=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<=n+1;i++){
		fs[i]=fs[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
//		cerr<<i<<'\n';
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
//			cerr<<l<<' '<<r<<' '<<mid<<'\n';
//			int L=get_l(i,mid);
//			cerr<<" ("<<L<<','<<L+mid-1<<')'<<'\n';
//			cerr<<" "<<((get_len(L,i)*a[i]-get_sum(L,i))+(get_sum(i,L+mid-1)-get_len(i,L+mid-1)*a[i]))<<'\n';
			if(check(i,mid)){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
//		cerr<<"ans:"<<r<<'\n';
		ans=max(ans,r);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/