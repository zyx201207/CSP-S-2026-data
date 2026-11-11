#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200010,maxt = 210;
int c,t;
int n[maxt],d[maxt],rsul[maxt];
struct xfx{
	int x[maxn];
}xtnn[maxt];
struct now_{
	
	int tnow;
	int ntt,dtt;xfx xtt,fret;
	inline void rett(){
		ntt=n[tnow];
		dtt=d[tnow];
		xtt=xtnn[tnow]; 
	}; 
	inline void fret_set(){
		for(int i=1;i<=ntt;i++){
			for(int j=i;j<=ntt;j++){
				if((xtt.x+j)-*(xtt.x+i)>d)fret.x[i]=j-1;
				break; 
			}; 
		}
		
	}
	inline int reso(){
		int sum=0;
		int mint=0;
		
		for(int i=1;i<=ntt;i++){
		int atf=xtt.x[fret.x[i]];
		int eps=1;
			for(int j=fret.x[i];j>=i+1;j--){
				
				if(xtt.x[j]==atf)eps++; 
				int eps=1;
		};
		if(eps==2)sum++;
		return sum;
	}
}}cot; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld",&n[maxt],&d[maxt]);
		for(int j;j<=n[i];j++){
			scanf("%lld",&xtnn[i].x[j]);
		}
		cot.tnow =i;
		cot.rett() ;
		cot.fret_set();
		;
		rsul[i]=cot.reso();
	}
	for(int i=1;i<=t;i++)printf("%d ",rsul);
};