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
	int a[N];
	void main(){
		int n,m,ans=0;
		cin>>n>>m;
		REP(i,1,n)cin>>a[i];
		DEP(o,30,0){
			int save=(1<<o+1)-1;
			sort(a+1,a+n+1,[&](int x,int y){
				return(x&save)>(y&save);
			});
			int pos=0;
			REP(i,1,n)
				if(a[i]>>o&1)pos=i;
				else break;
			if(pos>=m)ans|=(1<<o),n=pos;
		}
		cout<<ans;
	}
}
signed main(){
	IOS;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)WuJy::main();
	return 0;
}
