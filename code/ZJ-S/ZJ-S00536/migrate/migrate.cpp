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
#define INF 2000000000000000000
using namespace std;
int index;
namespace WuJy{
	const int N=2e6+5;
	int n;ll d,a[N];
	struct BIT{
		int a[N],o[N],tim=1;
		void add(int x,int k){
			for(;x<=n;x+=x&-x)
				if(o[x]!=tim)a[x]=k,o[x]=tim;
				else a[x]+=k;
		}int q(int x,int r=0){
			for(;x;x-=x&-x)
				if(o[x]==tim)r+=a[x];
			return r;
		}void cln(){tim++;}
		int ask(int l,int r){return q(r)-q(l-1);}
	}kd;
	void main(){
		cin>>n>>d;
		REP(i,1,n)cin>>a[i];
		ll ans=0;
		if(n<=5000){
			REP(i,1,n){
				int r=i,m=1;kd.cln(),kd.add(i,1);
				while(r<n){
					int nr=upper_bound(a+1,a+n+1,a[r]+d)-a-1;
					REP(j,r+1,nr){
						int l=lower_bound(a+1,a+n+1,a[j]-d)-a;
						int t=min(3,kd.ask(l,r));
						kd.add(j,t),ans+=t==2;
					}
					if(r==nr)break;
					r=nr;
				}
			}return cout<<ans<<'\n',void();
		}
		if((a[n]-a[1])/d<=15){
			REP(i,1,n){	
				int r=i,m=1;kd.cln();
				while(r<n){
					int nr=upper_bound(a+1,a+n+1,a[r]+d)-a-1; // (r,nr]
					int nm=nr-r,L=r+1,R=nr;
					if(!nm)break;
					if(kd.q(r))L=m>1?upper_bound(a+1,a+n+1,a[r-1]+d)-a:r+1;
					else{
						if(m==1)R=L-1;
						else R=upper_bound(a+1,a+n+1,a[r-1]+d)-a-1,
							 L=m>2?upper_bound(a+1,a+n+1,a[r-2]+d)-a:r+1;
					}
					MAX(L,r+1),MIN(r,nr);
					if(L<=R)kd.add(L,1),kd.add(R+1,-1),ans+=R-L+1;
					r=nr,m=nm;
					if(r>=n)break;
				}
			}return cout<<ans<<'\n',void();
		}
		
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;cin>>index>>T;
	while(T--)WuJy::main();
	return 0;
}
