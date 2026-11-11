#include<bits/stdc++.h>
#define MAXN 500010
using namespace std;
typedef long long ll;
int n,ans,logn[MAXN];
ll m,a[MAXN],st[MAXN][26],pre[MAXN];
inline void init(){
	logn[0]=-1;
	for(int i=1;i<=n;++i){
		logn[i]=logn[i>>1]+1;
		st[i][0]=a[i];
	} 
	logn[0]=0;
	for(int i=1;i<=logn[n];++i){
		for(int j=1;j<=n-(1<<i)+1;++j){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
//			cout<<j<<" "<<i<<" "<<st[j][i]<<endl;
		} 
	}
}
inline ll query_sum(int l,int r){
	return pre[r]-pre[l-1];
}
inline ll query_max(int l,int r){
	const int k=logn[r-l+1];
//	cout<<st[l][k]<<" "<<st[r-(1<<k)+1][k]<<endl;
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
inline ll cost(int l,int r){
	return query_max(l,r)*(r-l+1)-query_sum(l,r);
}
inline bool check(int mid){
	ll Cost=0;
	for(int l=1,r=mid;r<=n;++l,++r){
		if(cost(l,r)<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	init();
	int l=1,r=n,ans=1;
	while(l<=r){
		const int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}

