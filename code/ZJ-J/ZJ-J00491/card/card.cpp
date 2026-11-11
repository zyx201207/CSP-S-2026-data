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
	const int N=5e5+5,M=3e5+5;
	int a[N],nxt[M],now[M],ans[M],sz[N];
	void main(){
		int n,m;cin>>n>>m;
		REP(i,1,n)cin>>a[i];
		DEP(i,n,1)nxt[i]=now[a[i]],sz[now[a[i]]=i]=1;
		REP(i,1,n)
			if(nxt[i])sz[nxt[i]]+=sz[i];
			else ans[a[i]]=sz[i],sz[i+1]+=sz[i];
		REP(i,1,m)cout<<ans[i]<<" \n"[i==m];
	}
}
signed main(){
	IOS;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)WuJy::main();
	return 0;
}
