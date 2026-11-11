#include<bits/stdc++.h>
bool Med;
#define rep(i,j,k) for(int i=(j);(i)<=(k);(i)++)
#define per(i,j,k) for(int i=(j);(i)>=(k);(i)--)
#define i64 long long
#define u64 unsigned long long
#define inf 0x3f3f3f3f
#define inf64 0x3f3f3f3f3f3f3f3fll
namespace Staque{
	template<typename T,typename U>inline bool gmax(T &x,const U &y){return x<y?(x=y,1):0;}
	template<typename T,typename U>inline bool gmin(T &x,const U &y){return x>y?(x=y,1):0;}
	void Freopen(){freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);}
}using namespace Staque;
const int N=2000005;
i64 n,d,a[N];
namespace solve1{
	const int M=5005;
	int nxt[M],lst[M],SL[M],SR[M],tmp[M];
	void solve(){
		int RR=n;
		per(i,n,1){
			while(a[RR]-a[i]>d)RR--;
			nxt[i]=RR;
		}
		RR=1;
		rep(i,1,n){
			while(a[i]-a[RR]>d)RR++;
			lst[i]=RR;
		}
		int res=0;
		rep(i,1,n){
			rep(j,i+1,n){
				int cc=0,now=i,fll=0;
				while(now!=j){
					SL[++cc]=now;
					if(nxt[now]==now){fll=1;break;}
					now=std::min(nxt[now],j);
				}
				SL[++cc]=j;
				cc=0;
				while(now!=i){
					SR[++cc]=now;
					if(lst[now]==now){fll=1;break;}
					now=std::max(i,lst[now]);
				}
				SR[++cc]=i;
				std::reverse(SR+1,SR+1+cc);
				int ccc=0,fl=0;
				rep(i,1,cc)if(SL[i]!=SR[i]){
					fl=(SL[i]==SR[i]+1);
					ccc++;
				} 
				res+=(ccc==1&&fl==1&&fll==0);
			}
		}
		std::cout<<res<<"\n";
	}
}
namespace solve2{
	int lst[N],nxt[N];
	i64 f[N],g[N],h[N],l[N];
	void solve(){
		int RR=n;
		per(i,n,1){
			while(a[RR]-a[i]>d)RR--;
			nxt[i]=RR;
		}
		RR=1;
		rep(i,1,n){
			while(a[i]-a[RR]>d)RR++;
			lst[i]=RR;
		}
		rep(i,1,n){
			f[i]++;
			if(lst[nxt[i]]==i&&nxt[i]!=i)f[nxt[i]]+=f[i];
		}
		per(i,n,1){
			g[i]++;
			if(nxt[lst[i]]==i&&lst[i]!=i)g[lst[i]]+=g[i];
		}
		i64 res=0;
		rep(i,1,n){
			if(nxt[i]!=i)h[nxt[i]]+=f[i];
			if(lst[i]!=i)l[lst[i]]+=g[i];
		}
		int PR=1,PRR=1;
//		lst[1]=0,nxt[n]=n+1;
//		rep(i,1,n){
//			while(lst[PR]<nxt[i]-1&&PR<=n)PR++;
//			while(lst[PRR]<=nxt[i]-1&&PRR<=n)PRR++;
//			std::cout<<i<<' '<<PR<<' '<<PRR-1<<"\n";
//			rep(j,PR,PRR-1){
//				if(nxt[i]!=i&&lst[j]!=j&&i<j)res+=f[i]*g[j];
//			}
//		} 
		rep(i,1,n){
			rep(j,i+1,n){
				if(lst[j]<j&&nxt[i]>i&&i<j-1&&nxt[i]==lst[j]+1)
					res+=1ll*f[i]*g[j];
			}
		}
		rep(i,1,n)f[i]=g[i]=h[i]=l[i]=0;
		std::cout<<res<<"\n";
	}
}
void Init(){}
void testCase(){
	std::cin>>n>>d;
	rep(i,1,n)std::cin>>a[i];
	solve1::solve();
//	if(n<=5000)solve1::solve();
}
bool Mst;
int main(){
	Freopen();
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int TC=1,CC;
	std::cin>>CC>>TC;
	while(TC--)testCase();
	fprintf(stderr,"Memory:%.3lfMB\nTime:%.3lfs\n",(&Med-&Mst)/1048576.0,clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
/*
1 1
10 272727272727272724 -999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
