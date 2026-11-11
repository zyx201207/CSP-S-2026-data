#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int C,T;
ll n,d;
ll x[N];
ll solveA(){
	ll D=x[2]-x[1];
	if(d<2*D) return 0;
	ll t=d/D;
	return max(0ll,n-t*2+1);
}
ll cnt[N],pre[N];
void upd(int pL,int pR,int L,int R){
	//cout<<pL<<" "<<pR<<" "<<L<<" "<<R<<"\n";
	if(L>n || R>n) return;
	if(pR<pL){
		int nR=R+1;
		while(x[nR+1]-x[R]<=d && nR+1<=n) nR++;
		upd(L,R,R+1,nR);
		return;
	}
	int l=pL;
	for(int r=L;r<=R;r++){
		while(x[r]-x[l]>d && l<=pR) l++;
		cnt[r]=pre[pR]-pre[l-1];
		pre[r]=pre[r-1]+cnt[r];
	}
	int nR=R+1;
	while(x[nR+1]-x[R]<=d && nR+1<=n) nR++;
	upd(L,R,R+1,nR);
}
ll solve_small(){
	ll ans=0;
	for(int k=1;k<=n;k++){
		fill(cnt+1,cnt+n+1,0);
		fill(pre+1,pre+n+1,0);
		cnt[k]=1,pre[k]=1;
		upd(k,k-1,k,k);
		//cout<<k<<"cnt:";
		for(int i=k;i<=n;i++){
			//cout<<cnt[i]<<" ";
			ans+=(cnt[i]==2);
		}
		//cout<<'\n';
	}
	return ans;
}
void init(){
	memset(x,0,sizeof(x));
}
void wrk(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",x+i);
	if(C==0) {
		ll ans=solve_small();
		printf("%lld\n",ans);
	}
	if(1<=C && C<=10){
		ll ans=solve_small();
		printf("%lld\n",ans);
	}
	if(C==11 || C==12){
		ll ans=solveA();
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		init();
		wrk();
	}
	return 0;
}
/*
0 2
23 3
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
15 3
3 8 13 18 23 28 33 38 43 48 53 58 63 68 73


2->20
7->10
*/
