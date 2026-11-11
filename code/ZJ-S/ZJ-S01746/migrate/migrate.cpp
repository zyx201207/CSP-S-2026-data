#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define Rof(i,l,r) for(int i=(l);i>=(r);--i)
bool M_S;
namespace cjr2010{
	int SUB;
	const int N=(int)(2e6+5);
	int n,gap,p[N];
	int f[N][2][2][2][2];
	// b[i],flag1,b[i-1]<b[i]-2,i=2/>=3,p[b[i-1]-1]+d>=p[b[i]-1]
	// dont care the end,length must >=3,so start from length=2
	int g[N];
	void MAIN1(){
		cin>>n>>gap;
		For(i,1,n) cin>>p[i];
		// if(n>5000){cout<<"-1\n";return ;}//
		For(i,1,n) g[i]=upper_bound(p+1,p+n+1,p[i]+gap)-p;
		For(x,1,n){
		// For(x,1,1){//
			int y=g[x]-1;
			// For(i,x+1,n){
			// 	if(p[x]+gap>=p[i]) y=i;
			// 	else break;
			// }
			if(y==x) continue;
			f[y][0][x<y-2][0][p[x-1]+gap>=p[y-1]]++;
		}
		int ans=0;
		For(bi,2,n-1){
			int lim=g[bi]-1;
			int lim2=g[bi-1]-1;
			lim2=min(lim2,lim);
			int lim3=g[bi-1]-1;
			lim3=min(lim3,lim);
			int lim4=g[bi-2];// ???
			lim4=max(lim4,bi+1);
			int lim5=g[bi-1];
			int bj=g[bi]-1;
			For(a,0,1){
				For(b,0,1){
					For(c,0,1){
						For(d,0,1) if(f[bi][a][b][c][d]){
							// int lim=upper_bound(p+1,p+n+1,p[bi]+gap)-p-1;
							if(!a){
								if(!(c&&d)){
									if(!b){
										// int lim2=upper_bound(p+1,p+n+1,p[bi-1]+gap)-p-1;
										// lim2=min(lim2,lim);
										ans+=max(0ll,lim2-(bi+1)+1)*f[bi][a][b][c][d];
										// For(br,bi+1,lim){
										// 	if(p[bi-1]+gap>=p[br]) ans+=f[bi][a][b][c][d];
										// }
									}
									else{
										// int lim3=upper_bound(p+1,p+n+1,p[bi-1]+gap)-p-1;
										// lim3=min(lim3,lim);
										// int lim4=upper_bound(p+1,p+n+1,p[bi-2]+gap)-p;
										// lim4=max(lim4,bi+1);
										ans+=max(0ll,lim3-lim4+1)*f[bi][a][b][c][d];
										// For(br,bi+1,lim2){
										// 	if(p[bi-2]+gap<p[br]) ans+=f[bi][a][b][c][d];
										// }
									}
								}
							}
							else{
								// int lim5=upper_bound(p+1,p+n+1,p[bi-1]+gap)-p;
								ans+=max(0ll,lim-lim5+1)*f[bi][a][b][c][d];
							}
							
							// int bj=upper_bound(p+1,p+n+1,p[bi]+gap)-p-1;
							// For(i,bi+1,n){
							// 	if(p[bi]+gap>=p[i]) bj=i;
							// 	else break;
							// }
							if(bj==bi) continue;
							bool flag1=a,flag2=0;
							if(p[bi-1]+gap>=p[bj]){
								if(flag1){
									flag2=1;
								}
								flag1=1;
								if(b&&p[bi-2]+gap>=p[bj]){
									flag2=1;
								}
								if(c&&d){
									flag2=1;
								}
							}
							if(!flag2){
								f[bj][flag1][bi<bj-2][1][p[bi-1]+gap>=p[bj-1]]+=f[bi][a][b][c][d];
							}
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	void _MAIN1(){
		// memset(f,0,sizeof(f));
		For(i,0,n) For(a,0,1) For(b,0,1) For(c,0,1) For(d,0,1) f[i][a][b][c][d]=0;
	}
	int T;
	void MAIN(){
		cin>>SUB>>T;
		For(_,1,T) MAIN1(),_MAIN1();
	}
}
bool M_T;
signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	double T_S=clock();cjr2010::MAIN();double T_T=clock();
	cerr<<(T_T-T_S)/CLOCKS_PER_SEC<<"s\n";
	cerr<<(&M_S-&M_T)/1048576.0<<"MiB\n";
	return 0;
}
/*
migrate
g++ 1.cpp -o 1 -O2 -std=c++14 -static && .\1
*/