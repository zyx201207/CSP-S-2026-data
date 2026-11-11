#include<bits/stdc++.h>
#define IOS cin.tie(0)->sync_with_stdio(0)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define DEP(i,a,b) for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define RAP(i,a) for(auto i=(a).begin();i!=(a).end();i++)
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
	const int N=2e5+5;
	pair<ll,char>qu[N];
	int bg,ed;
	void main(){
		int n;cin>>n,bg=1,ed=n;
		REP(i,1,n)cin>>qu[i].fi>>qu[i].se;
		ll ans=0;
		while(bg<ed){
			ll dlt=min(qu[bg].fi,qu[ed].fi);
			if(qu[bg].se!=qu[ed].se)ans+=dlt;
			qu[bg].fi-=dlt;if(!qu[bg].fi)bg++;
			qu[ed].fi-=dlt;if(!qu[ed].fi)ed--;
		}
		cout<<ans;
	}
}
signed main(){
	IOS;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)WuJy::main();
	return 0;
}
