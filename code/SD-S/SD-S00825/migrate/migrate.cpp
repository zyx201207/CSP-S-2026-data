#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
#define mod 998244353
using namespace std;
const int N=2e6+10;
ll ksm(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res;
}
ll fact[N],invfact[N];
void init(int n){
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
	invfact[n]=ksm(fact[n],mod-2);
	for(int i=n-1;i>=0;i--) invfact[i]=(invfact[i+1]*(i+1))%mod;
}
ll C(int n,int m){
	if(n<0||m>n) return 0;
	return fact[n]*invfact[m]%mod*invfact[n-m]%mod;
}
void solve(){
	int n;
	ll d;
	scanf("%d %lld",&n,&d);
	vector<ll> x(n,0);
	for(int i=0;i<n;i++) scanf("%lld",&x[i]);
	if(n<=10000){
		int ans=0;
		vector<vector<int>> g(n);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(x[j]-x[i]<=d) g[i].push_back(j);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				
			}
		}
		printf("%d\n",ans);
		return;
	}
	vector<int> g1,g2;
	for(int i=0;i<n;i++){
		int id=upper_bound(x.begin(),x.end(),d+x[i])-x.begin()-1;
		int len=id-i+1;
		if(len==1) g1.push_back(i);
		if(len==2) g2.push_back(i);
		
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	scanf("%d %d",&c,&t);
	init(N-1);
	while(t--){
		solve();
	}
	
	
	return 0;
} 
