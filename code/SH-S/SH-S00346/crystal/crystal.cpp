#include<bits/stdc++.h> 
#define N 500003
using namespace std;
typedef long long ll;
ll n,m,a[N],s[N];
ll Abs(ll t){
	if(t<0)return -t;
	return t;
}
void input(){
	scanf("%lld%lld",&n,&m);
	ll minai=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1)minai=a[1];
		else minai=min(minai,a[i]);
	}
//	printf("min a_i=%lld\n",minai);
	for(ll i=1;i<=n;i++)
		a[i]+=(minai+1);
}
bool okA(){
	for(ll i=1;i<=n;i++)
		if((a[i]-i)!=0)return 0;
	return 1;
}
void solveA(){
	ll k=(ll)(sqrt(2*m)-0.5)-3;
	while(k*(k+1)<=2*m)k++;
	printf("%lld\n",k);
}
bool okB(){
	for(ll i=3;i<=n;i++)
		if((a[i]+a[i-2]-2*a[i-1])!=0)
			return 0;
	return 1;
}
void solveB(){
	ll d=Abs(a[1]-a[2]);
	ll k=(ll)(sqrt(2.0*m/d)-0.5)-3;
	if(d==0){
		printf("%lld\n",n);
		return;
	}
	while(k*(k+1)*d<=2*m)k++;
	printf("%lld\n",k);
}
ll ret=-1;
ll b[13];
void dfs(ll k,ll M){// deciding k
//	printf("Now k=%lld,M=%lld\n",k,M);
//	for(int i=1;i<=n;i++)
//		printf("%lld ",a[i]);
//	printf("\n");
	if(k==n+1||M==0){
		for(ll i=1;i<=n;i++)
			b[i]=a[i];
		sort(b+1,b+1+n);
		ll num=-1;
		for(int i=1;i<=n;i++){
			ll cnt=0,tmp=b[i];
			while(b[i]==tmp)i++,cnt++;
			num=max(num,cnt);
		}
		ret=max(ret,num);
//		printf("num=%lld\n",num);
		return;
	}
	if(k==n){
		a[n]+=M;
		dfs(n+1,0);
		a[n]-=M;
	}
	for(ll dM=0;dM<=M;dM++){
		a[k]+=dM;
		dfs(k+1,M-dM);
		a[k]-=dM;
	}
}
void solvebf(){
	dfs(1,m);
	printf("%lld\n",ret);
}
bool ok(ll T,ll l){
	bool re=((l-1)*a[T+l-1])-m<=(s[T+l-2]-s[T-1]);
//	printf("Pending %lld,%lld: %d\n",T,l,re);
	return re;
}
void solve(){
//	printf("%d\n",1);
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
//	for(ll i=1;i<=n;i++)
//		printf("%lld ",a[i]);
//	printf("\n");
//	for(ll i=1;i<=n;i++)
//		printf("%lld ",s[i]);
//	printf("\n");
	ll ans=-1;
	for(ll T=1;T<=n;T++){
//		printf("\nT=%lld\n",T);
		ll l=2,r=n-T+1,tmp=-1;
		while(l<r){
//			printf("l=%lld,r=%lld\n",l,r);
			ll mid=l+(r-l)/2;
			if(ok(T,mid)){
				if(l==mid){
					tmp=l;
					break;
				}else l=mid,tmp=mid;
			}
			else r=mid-1;
		}
		ans=max(ans,tmp-(1-ok(T,tmp)));
	}
	printf("%lld\n",ans);
}
int main(){// (31)8=(25)10
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	if(okA())solveA();
	else if(okB())solveB();
	else if(n<=5&&m<=10)solvebf();
	else solve();
//	solve();
	return 0;
}
