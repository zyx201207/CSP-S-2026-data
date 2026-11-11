#include<bits/stdc++.h>
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define ll long long
#define db double 
#define pb push_back
#define eb emplace_back
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memset(x,y,sizeof(x))
#define PII pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=2e6+20,M=1e5+20;
const ll INF=1e18,mod=998244353;
// namespace H_H_READ{
// 	char Buf[1<<23],*P1=Buf,*P2=Buf;
// 	#define gc() (P1==P2 && (P2=(P1=Buf)+fread(Buf,1,1<<23,stdin),P2==P1?EOF:*P1++))
// 	#define Tp template<typename T>
// 	// #define Ts template<typename T,typename ...args>
// 	Tp void read(T &o){
// 		int f=0;o=0;int ch=gc();
// 		while(ch<'0' || ch>'9') f=ch=='-',ch=gc();
// 		while('0'<=ch && ch<='9') o=(o<<1)+(o<<3)+(ch^48),ch=gc();
// 		if(f) o=-o;
// 	}
// 	Tp void write(T o){
// 		if(o<0) o=-o,puchar('-');
// 		if(o>9) write(o/10);
// 		putchar(o%10+"0");
// 	}
// }using H_H_READ::read;using H_H_READ::write;
namespace H_H{
	int n,L[N],R[N],nxt[N],pre[N],Lmn[N],Lmx[N],Rmn[N],Rmx[N];
	ll d,a[N];
	inline void init(){
		for(int i=1;i<=n;i++){
			L[i]=R[i]=0;
			Lmn[i]=Rmn[i]=mod;
			Lmx[i]=Rmx[i]=0;
		}
	}
	inline void get(){
		for(int i=1,j=1;i<=n;i++){
			while(j<n && a[j+1]-a[i]<=d) j++;
			nxt[i]=j;
			if(i!=j){
				Lmn[j]=min(Lmn[j],i);
				Lmx[j]=max(Lmx[j],i);				
			}
		}
		for(int i=n,j=n;i>=1;i--){
			while(j>1 && a[i]-a[j-1]<=d) j--;
			pre[i]=j;
			if(i!=j){
				Rmn[j]=min(Rmn[j],i);
				Rmx[j]=max(Rmx[j],i);				
			}
		}
	}
	inline void calc(){
		for(int i=1;i<=n;i++){
			if(pre[i]==i) continue;
			if(Lmn[i]<=Lmx[i]) L[i]=Lmx[i]-Lmn[i]+1;
			if(nxt[pre[i]]==i) L[i]+=L[pre[i]];
		}
		for(int i=n;i>=1;i--){
			if(nxt[i]==i) continue;
			if(Rmn[i]<=Rmx[i]) R[i]=Rmx[i]-Rmn[i]+1;
			if(pre[nxt[i]]==i) R[i]+=R[nxt[i]];
		}
	}
	void solve(){
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++) cin>>a[i];
		get();calc();
		// for(int i=1;i<=n;i++) cout<<pre[i]<<" ";
		// cout<<"\n";
		// for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
		// cout<<"\n";
		// for(int i=1;i<=n;i++) cout<<L[i]<<" ";
		// cout<<"\n";
		// for(int i=1;i<=n;i++) cout<<R[i]<<" ";
		// cout<<"\n";
		ll ans=0;
		for(int i=1;i<n;i++){
			// if(pre[i+1]==i || nxt[i]==i+1) continue;
			if(Rmn[i]>Rmx[i] || Lmn[i+1]>Lmx[i+1]) continue;
			ll tpl=Lmx[i+1]-Lmn[i+1]+1-(nxt[i]==i+1),tpr=Rmx[i]-Rmn[i]+1-(pre[i+1]==i);
			int mn=Lmn[i+1],mx=Rmx[i];
			if(mn==i || mx==i+1) continue;
			if(pre[i]==mn) tpl+=L[mn];
			if(nxt[i+1]==mx) tpr+=R[mx];
			ans+=tpl*tpr;
		}
		cout<<ans<<"\n";
	}
	int main(){
		int c,T=1;cin>>c>>T;
		while(T--) solve();
		return 0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;H_H::main();
	// cerr<<(db)clock()/CLOCKS_PER_SEC<<"\n";
	return 0;
}
//g++ 1.cpp -o 1 -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow "-Wl,--stack=1234567890"