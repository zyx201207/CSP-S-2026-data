#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define DEP(i,a,b) for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define MOD(a) (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=(mod+(a)+(b))%mod
#define SUB(a,b) (a)=(mod+(a)-(b))%mod
#define MUL(a,b) (a)=(1ll*(a))*((b)%mod)%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define INF 2000000000
using namespace std;
namespace WuJy{
	const int N=5e5+5;
	ll a[N];
	void main(){
		int n,ans=0;ll m;cin>>n>>m;
		vector<ll>H(n);
		REP(i,1,n)cin>>a[i];
		sort(a+1,a+n+1);
		ll cst=0;
		priority_queue<ll>pq;
		REP(i,1,n){
			cst+=pq.size()*(a[i]-a[i-1]);
			while(cst>m)cst-=a[i]+pq.top(),pq.pop();
			pq.push(-a[i]);
			MAX(ans,SZ(pq));
		}
		cout<<ans;
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)WuJy::main();
	return 0;
}
