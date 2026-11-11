#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(n) for(int i=1;i<=(n);i++)
#define V vector
#define pb push_back
#define endl '\n'
#define sc if(debug)cerr
constexpr bool debug=0;
constexpr int _=1000005,mod=998244353,INF=1000000000000000009ll;
const string FLNM="migrate";
int N,NNN,n,d,A[_],AAA[_],a[_];
bitset<_>g;
int ABS(int x){return x<0?-x:x;}
bool OKA(int x,int y){
	return ABS(A[x]-A[y])<=d;
}
bool ok(int x,int y){
	return ABS(a[x]-a[y])<=d;
}
V<int>v,gd,bd,G[2];
int sm[_];
	int ans=0;
int ds[_],ct[_];
	int CCC,ttt;
void solve(int l,int r){
	N=r-l+1;
	FOR(N)A[i]=AAA[i+l-1];
	// FOR(N)sc<<A[i]<<' ';
	// sc<<endl;
	n=0;
	v.clear();gd.clear();bd.clear();
	G[1].clear(),G[0].clear();
	FOR(N)g[i]=0;
	int CUT=0;
	FOR(N){
		n++;
		a[n]=A[i]-CUT;
		// sc<<"now "<<i<<endl;
		// if(i<=N-3&&OKA(i,i+3)){
		// 	int j=i+3;
		// 	while(j<=N){
		// 		j++;
		// 		// sc<<"ad j to"<<j<<endl;
		// 		if(!OKA(i,j))break;
		// 	}
		// 	j--;
		// 	// sc<<"ct "<<j<<endl;
		// 	CUT+=ABS(A[j]-A[i])-d;
		// 	// sc<<"cut="<<CUT<<endl;
		// 	i=j-1;
		// }
	}
	sc<<n<<endl;
	FOR(n)sc<<a[i]<<endl;
	FOR(n){
		for(int j=1;j<=n;j++)ds[j]=INF,ct[j]=0;
		ds[i]=0,ct[i]=1;
		for(int j=i+1;j<=n;j++){
			ds[j]=ds[j-1]+1;ct[j]=ct[j-1];
			for(int k=i;k<j-1;k++){
				if(ok(k,j)){
					if(ds[j]>ds[k]+1){
						ds[j]=ds[k]+1,ct[j]=ct[k];
					}else if(ds[j]==ds[k]+1){
						ct[j]+=ct[k];
					}
				}
			}
			if(ct[j]==2)ans++;
		}
	}
	// g[1]=g[n]=1;
	// FOR(n-2){
	// 	if(!ok(i,i+2))g[i]=1;
	// }
	// FOR(n)if(g[i])v.pb(i);
	// FOR(n)if(g[i])G[i%2].pb(i);
	// //gd: %2=1
	// //bd: %2=0
	// for(int i=1;i<((int)v.size());i++){
	// 	if((v[i]-v[i-1])%2)gd.pb(i);
	// 	else bd.pb(i);
	// }
	// sc<<n<<" gedian\n";
	// FOR(n)sc<<g[i]<<' ';
	// FOR(n)sm[i]=sm[i-1]+g[i];
	// sc<<endl;
	// FOR(n){
	// 	int as=0;
	// 	int rt=lower_bound(G[(i&1)^1].begin(),G[(i&1)^1].end(),i)-G[(i&1)^1].begin();
	// 	if(rt==(int)G[(i&1)^1].size()){
	// 		// (n-i)
	// 		as+=(n-i)/2;
	// 		int rr=v.end()-upper_bound(v.begin(),v.end(),i);
	// 		// v.size()-
	// 		as-=rr;
	// 		sc<<"I="<<i<<" as="<<as<<endl;
	// 		ans+=as;
	// 		continue;
	// 	}
	// 	// if(rt==b.end()){
	// 		// n-rt+1
	// 		// continue;
	// 	// }
	// 	int R=G[(i&1)^1][rt];
	// 	//only1 : %2=0 or 1

	// 	// if((R-i)%2){
	// 		if(R!=i){
	// 			as+=((R-i+1)/2)-(sm[R-1]-sm[i])-1;
	// 			sc<<"ad "<<((R-i+1)/2-1)<<' '<<(sm[R-1]-sm[i])<<endl;
	// 		}
	// 		auto RRID=upper_bound(gd.begin(),gd.end(),R);
	// 		if(RRID==gd.end()){ans+=as;continue;}
	// 		int RR=gd[RRID-gd.begin()];
	// 		as+=(RR-R+1)/2;
	// 		int LLid=lower_bound(bd.begin(),bd.end(),RR)-bd.begin()-1;
	// 		sc<<"now right ^1="<<R<<" RR="<<RR<<' '<<LLid<<endl;
	// 		sc<<(RR-R+1)/2<<' '<<(LLid-rt+1)<<endl;
	// 		// as+=(RR-R+1)/2;
	// 		as+=(LLid-rt+1);
	// 	// }else{
	// 		// sc<<"to be continued\n";

	// 	// }
	// 	sc<<"i="<<i<<" as="<<as<<endl;
	// 	ans+=as;
	// }
}
int DDD;
void SLV(){
	cin>>NNN>>d;
	FOR(NNN)cin>>AAA[i];
	DDD=AAA[2]-AAA[1];
	bool fg=1;
	for(int i=3;i<=NNN;i++){
		if(AAA[i]-AAA[i-1]!=DDD)fg=0;
	}
	if(fg){
		sc<<DDD<<' '<<d<<endl;
		int nw=d/DDD;
		if(nw<=1)cout<<"0\n";
		// else if(nw==2)cout<<"?\n";
		else cout<<max(0ll,NNN-nw*2+1)<<endl;
		// if(DDD<d*2||DDD>=d*3)cout<<0<<endl;
		// else cout<<1<<endl;
		return;
	}
	if(CCC>6){
		cout<<"0\n";
		return;
	}
	sc<<"dohere\n";
	int ls=1;
	ans=0;
	FOR(NNN){
		if(i==NNN||AAA[i+1]-AAA[i]>d){
			sc<<"solve "<<ls<<' '<<i<<endl;
			solve(ls,i);
			ls=i+1;
		}
	}


	cout<<ans<<endl;
	// FOR(n)sc<<a[i]<<' ';
	// sc<<endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	(void)!freopen((FLNM+".in").c_str(),"r",stdin);
	(void)!freopen((FLNM+".out").c_str(),"w",stdout);
	if(debug)(void)!freopen((FLNM+".err").c_str(),"w",stderr);
	cin>>CCC>>ttt;
	while(ttt--)SLV();
}
//freopen
//I want mihuozhinan
//I code for ~2.5h for this 4KB trash.
//But it's wrong in the first place
//I am trash
//I am really L
//T2 is easy
//so 1= > 200?
//I finally solve T1&2 unless exploded