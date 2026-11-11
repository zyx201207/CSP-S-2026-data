#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n;
int l[N],r[N];
ll x[N],d;
namespace solve1{
	int cnt[N];
	int stk[N],top;
	void calc(){
		ll ans=0;
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=1;j<=n;j++) cnt[j]=0;
			for(int j=i;j;j=r[j]){
				stk[++top]=j;
				if(r[j]==j) break;
			}
//			cerr<<"now:"<<i<<'\n';
//			for(int j=1;j<=top;j++) cerr<<stk[j]<<' ';
//			cerr<<'\n';
			for(int j=1;j<top;j++){
				//(stk[i],stk[i+1]] 
				for(int x=stk[j]+1;x<=stk[j+1];x++){
					int to=max(l[x],i);
					cnt[x]=cnt[to]+(stk[j]-to);
//					cerr<<"??? "<<x<<' '<<to<<' '<<cnt[x]<<'\n';
					if(cnt[x]==1) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
namespace solve2{
	int f[N],g[N];
	int cf[N],cg[N];
	ll ans;
	vector<int>A[N],B[N];
	void calc(){
		ans=0;
		for(int i=1;i<=n;i++){
			if(r[i]!=i && l[r[i]]!=i) cf[r[i]]++;
			if(l[i]!=i && r[l[i]]!=i) cg[l[i]]++;
			if(r[i]!=i) A[r[i]].push_back(i);
			if(l[i]!=i) B[l[i]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			int x=r[i];
			f[i]+=cf[i]+(x!=i);
			if(x!=i && l[x]==i) f[x]+=f[i];
		}
		for(int i=n;i>=1;i--){
			int x=l[i];
			g[i]+=cg[i]+(x!=i);
			if(x!=i && r[x]==i) g[x]+=g[i];
		}
//		for(int i=1;i<=n;i++) cerr<<f[i]<<' '<<cf[i]<<' '<<g[i]<<' '<<cg[i]<<'\n';
		for(int i=1;i<n;i++){
			ll L=0,R=0;
			if(r[l[i]]==i+1) L=f[l[i]];
			else if(r[l[i]]==i) L=A[i+1].size()-(r[i]==i+1);
			if(l[r[i+1]]==i) R=g[r[i+1]];
			else if(l[r[i+1]]==i+1) R=B[i].size()-(l[i+1]==i);
			ans+=L*R;
//			cerr<<"??? "<<i<<' '<<i+1<<' '<<L<<' '<<R<<'\n';
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			f[i]=cf[i]=g[i]=cg[i]=0;
			A[i].clear(),B[i].clear();
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int pos=1;
	for(int i=1;i<=n;i++){
		while(pos<=n && x[pos]-x[i]<=d) pos++;
		r[i]=pos-1;
	}
	pos=n;
	for(int i=n;i>=1;i--){
		while(pos>=1 && x[i]-x[pos]<=d) pos--;
		l[i]=pos+1;
	}
	if(c<=10) solve1::calc();
	else solve2::calc();
	for(int i=1;i<=n;i++) l[i]=r[i]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 1
10 4
0 3 5 6 10 14 16 17 19 22 

0 1
9 5
0 3 6 8 11 12 16 20 24 
*/
