#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(auto i=(l);i<=(r);i++)
#define irep(i,l,r) for(auto i=(l);i>=(r);i--)
#define sc cerr
#define qlog(x) {sc<<#x<<"="<<(x)<<"\n";}
#define qloga(a,l,r) {sc<<#a<<": "; rep(I,l,r){sc<<a[I]<<" ";} sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<": "; for(const auto &x:a){sc<<x<<" ";} sc<<"\n";}
typedef long long ll;
typedef __int128 i128;

#define int ll
constexpr int N=2e6+10;
int C,T;
ll n,d,a[N];
ll l[N],r[N];
ll L[N],R[N];
ll uL[N], uR[N];

bool go(int i,int j){
	return llabs(a[i]-a[j])<=d;
}

ll solve(){
	cin>>n>>d;
	rep(i,1,n)cin>>a[i];


	rep(i,1,n){
		l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
		r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
	}
	rep(i,1,n)if(l[i]==1 && r[i]==n)return 0;

	rep(i,1,n){
		if(l[i]!=i && r[l[i]]==i)L[i]=L[l[i]]+1;
		else L[i]=1;
		if(L[i]!=1)uL[i]=l[i];
		else uL[i]=0;
	}
	irep(i,n,1){
		if(r[i]!=i && l[r[i]]==i)R[i]=R[r[i]]+1;
		else R[i]=1;
		if(R[i]!=1)uR[i]=r[i];
		else uR[i]=0;

	}
	if(0){
	rep(i,1,n)sc<<i<<" ";
	sc<<"\n";
	qloga(l,1,n);
	qloga(r,1,n);
	qloga(L,1,n);
	qloga(R,1,n);
	}

	rep(i,1,n)L[i]+=L[i-1];
	rep(i,1,n)R[i]+=R[i-1];

	ll ans=0;
	rep(i,1,n-1){
		ll l1,r1,l2,r2;
		l1=l[i+1];
		r2=r[i];
		if(i-1>=1)l2=r[i-1]+1;
		if(i+2<=n)r1=l[i+2]-1;

		l2=max(l2,(ll)i+2);
		r1=min(r1,(ll)i-1);

		l1=max(l1,1LL);
		l2=max(l2,1LL);
		r1=min(r1,n);
		r2=min(r2,n);

		if(l1>r1)continue;
		if(l2>r2)continue;
		rep(x,l1,r1)rep(y,l2,r2){
		}
		ll ctb=(L[r1]-L[l1-1])*(R[r2]-R[l2-1]);
		//qlog(ctb);
		ans+=ctb;


		//sc<<i<<","<<i+1<<"\n";
		//sc<<"["<<l1<<","<<r1<<"]  ["<<l2<<","<<r2<<"]\n";
		//ll ctb=(L[r1]-L[l1-1])*(R[r2]-R[l2-1]);

		if(0){
			rep(x,1,i-1)rep(y,i+2,n){
				if(go(x,i+1) && go(y,i) && (!go(x,i+2) || i+2>n) && (!go(y,i-1) || i-1<1)){
					//sc<<x<<","<<y<<"\n";
					qlog((L[x]-L[x-1])*(R[y]-R[y-1]));
				}
			}
		}
	}
	//check(2,5);
	//return -1;
	//rep(i,1,n)rep(j,i+1,n)if(check(i,j)){ sc<<i<<","<<j<<"\n"; }
	return ans;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>C>>T;
	while(T--)cout<<solve()<<"\n";
}

