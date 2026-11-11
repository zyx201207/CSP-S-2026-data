#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define PLL pair<LL,LL>
#define mp make_pair
#define mod ((LL)1e9+7)
#define inf ((LL)0x3f3f3f3f3f3f3f3f)
#define esp ((long double)1e-7)
#define len(x) ((LL)(x.size()))
inline LL mo(const LL x){return x-x/mod*mod;}
inline LL mo(const LL x,const LL p){return x-x/p*p;}
inline LL _mo(const LL x,const LL p){return mo(mo(x,p)+p,p);}
#define N ((LL)2e6+7)
LL n,d,ans,l[N],r[N],x[N];
inline LL erfen(LL q){
	LL L=1,R=n;
	while(L<R){
		LL mid=(L+R+1)>>1;
		if(x[mid]<=q){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	return L;
}
inline void solve(){
	cin>>n>>d;
	ans=0;
	l[1]=r[n]=1;
	for(LL i=1;i<=n;++i){
		cin>>x[i];
	}
	for(LL i=2,left=1;i<n-2;++i){
		while(x[i]-x[left]>d){
			++left;
		}
		l[i]=1;
		if(left!=i && x[i+1]-x[i-1]>d){
			l[i]+=l[left];
		}
	}
	for(LL i=n-1,right=n;i>3;--i){
		while(x[right]-x[i]>d){
			--right;
		}
		r[i]=1;
		if(right!=i && x[i+1]-x[i-1]>d){
			r[i]+=r[right];
		}
	}
	for(LL i=1;i<=n-3;++i){
		LL nxt=erfen(x[i]+d);
		if(nxt<=i+1){
			continue;
		}
		LL R=erfen(x[nxt-1]+d),L=erfen(x[nxt-2]+d);
		if(L>=R || x[L+1]-x[nxt-2]<=d){
			continue;
		}
		ans+=l[i]*(R-L-1+r[R]);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	LL c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
