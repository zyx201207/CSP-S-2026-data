#include <bits/stdc++.h>
#include <assert.h>
#include <limits.h>
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back 
#define fi first
#define se second
#define pct(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define lowbit(x) ((x)&-(x))
#define dbg(x) cerr<<"Line= "<<__LINE__<<" : "<<#x<<"= "<<x<<endl;
using namespace std;
constexpr int N=2000010,base=389,mod=998244353;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;

template<class T> inline void ckmin(T &x,T y){x=(x<y)?x:y;}
template<class T> inline void ckmax(T &x,T y){x=(x>y)?x:y;}

namespace Zhchz{
	int C,T,n,D,X[N];
	
	int d[2000010],c[2000010];
	namespace N5000{
	int solve(){
		int ans=0;
		for(int L=1;L<=n;L++){
			d[L-1]=c[L-1]=0;
			d[L]=0;c[L]=1;
			for(int R=L+1;R<=n;R++){
				int l=lower_bound(X+L,X+R+1,X[R]-D)-X;
				int r=upper_bound(d+l,d+R,d[l])-d-1;
				d[R]=d[l]+1;c[R]=c[R-1]+c[r]-c[l-1];
				int t=c[R]-c[R-1];
				ans+=(t==2);
			}
		}
		return ans;
	}
	}
	namespace NA{
	int solve(){
		int ans=0;
		d[0]=c[0]=0;
		d[1]=0;c[1]=1;
		int rr=1;
		for(int R=2;R<=n;R++){
			int l=lower_bound(X+1,X+R+1,X[R]-D)-X;
			int r=upper_bound(d+l,d+R,d[l])-d-1;
			int p=c[l]-c[l-1];
			if(p!=1) break;
			d[R]=d[l]+1;c[R]=c[R-1]+c[r]-c[l-1];
			int t=c[R]-c[R-1];
			if(t==2){ans++;rr=R;}
		}
		return ans*(n-rr+1);
	}
	}
	
	int Solve(){
		cin>>n>>D;
		for(int i=1;i<=n;i++) cin>>X[i];
		if(n<=5000) return N5000::solve();
		bool fA=1;
		for(int i=2;i<n && fA;i++){
			fA&=(X[i-1]+X[i+1]==2*X[i]);
		}
		if(fA) return NA::solve();
		return N5000::solve();
	}
	
	signed main(){
		ios::sync_with_stdio(0);cin.tie(0);
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin>>C>>T;
		while(T--)
			cout<<Solve()<<"\n";
		return 0;
	}
}signed main(){return Zhchz::main();}
