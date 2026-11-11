#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cll const long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define all(x) x.begin(),x.end()
#define ld long double
using namespace std;
cll N=2e6+9;
int c; ll n,d,x[N]; 
bool OK(ll i,ll j){
	if(i>j)swap(i,j);
	if(i<1||j>n)return 0;
	return x[j]-x[i]<=d;
}
namespace BF{
	ll dst[309][309],cnt[309][309];
	void solve(){
		rep(i,1,n)rep(j,1,n){
			dst[i][j]=(OK(i,j)?1:1e18);
			cnt[i][j]=(OK(i,j)&&i!=j);
		}
		rep(i,1,n)dst[i][i]=0;
		rep(k,1,n)rep(i,1,n)rep(j,1,n){
			ll S=dst[i][k]+dst[k][j],C=cnt[i][k]*cnt[k][j];
			if(S==dst[i][j])cnt[i][j]+=C;
			else if(S<dst[i][j])dst[i][j]=S,cnt[i][j]=C;
		}
		ll ans=0;
		rep(i,1,n)rep(j,i,n)if(cnt[i][j]==2)ans++;
		cout<<ans<<endl;
	}
}
void solveA(){
	d/=x[2]-x[1];
	if(d<=1)cout<<0<<endl;
	else cout<<max(0ll,n-2*d+1)<<endl;
}
void solveB(){
	ll S; rep(i,1,n)if(OK(i,1)&&OK(i,n)){S=i; break;}
	ll t1=0; Rep(i,S+1,n)if(!OK(i,S-1)) t1++; 
	ll t2=0; rep(i,1,S-1)if(OK(i,S+1)&&!OK(i,S+2)) t2++;
	ll s1=0; Rep(i,S+1,n)if(OK(i,S-1)&&!OK(i,S-2)) s1++; 
	ll s2=0; rep(i,1,S-1)if(!OK(i,S+1)) s2++;
	cout<<t1*t2+s1*s2<<endl; 
}
ll pre[N],suf[N];
ll L[N],R[N];
void initLR(){
	ll j=1; rep(i,1,n){while(!OK(i,j))j++; L[i]=j;} L[n+1]=n;
	j=n; Rep(i,1,n){while(!OK(i,j))j--; R[i]=j;} R[0]=1;
}
void dp(){
	pre[1]=0; rep(i,2,n)if(!OK(L[i],i+1))pre[i]=pre[L[i]]+L[i+1]-L[i]; else pre[i]=L[i+1]-L[i];
	suf[n]=0; Rep(i,1,n-1)if(!OK(R[i],i-1))suf[i]=suf[R[i]]+R[i]-R[i-1]; else suf[i]=R[i]-R[i-1];
//	rep(i,1,n)pre[i]+=i-L[i+1],suf[i]+=R[i-1]-i;
}
ll L1(ll S){return L[S+2]-L[S+1];}
ll R1(ll S){return R[S]-R[S-1];}
ll L2(ll S){return L[S+1]<L[S+2]&&L[S]==L[S+1]?pre[L[S]]:0;}
ll R2(ll S){return R[S]>R[S-1]&&R[S]==R[S+1]?suf[R[S+1]]:0;}
void solve(){
	initLR();
	dp(); ll ans=0;
	rep(S,1,n-1)if(OK(S,S+2)&&OK(S-1,S+1))ans+=(L1(S)+L2(S))*(R1(S)+R2(S));
//	rep(S,1,n-1)if(L1(S)+L2(S))cout<<S<<" "<<L1(S)<<" "<<L2(S)<<" "<<R1(S)<<" "<<R2(S)<<endl;
//	rep(i,1,n)cout<<L[i]<<" "<<R[i]<<endl;
//	rep(i,1,n)if(pre[i])cout<<i<<" P"<<pre[i]<<" S"<<suf[i]<<endl;
	cout<<ans<<endl;
}
void work(){
	cin>>n>>d; rep(i,1,n)cin>>x[i];
	if(c<=6)BF::solve();
	else if(c==11||c==12)solveA();
//	else if(c==13||c==14)solveB(); // need check
	else solve();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	int T=1; cin>>c>>T;
	while(T--)work();
	return 0;
}

