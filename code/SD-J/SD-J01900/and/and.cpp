#include <iostream>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,x,ans,cumc[35];
bool a[N][35],f[N],ky[N];
int poww(int x){return cumc[x];}
void jjz(int ip,int x){
	for(int i=31;i>=0;--i){
		int resf=poww(i);
		if(x>=resf){
			x-=resf;
			a[ip][i]=1;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cumc[0]=1;
	for(int i=1;i<=32;++i){
		cumc[i]=cumc[i-1]*2;
	}
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&x);
		jjz(i,x);ky[i]=1;
	}
	for(int i=31;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j) f[j]=0;
		for(int j=1;j<=n;++j){
			if(a[j][i]==1&&ky[j]){
				f[j]=1;
				cnt++; 
			}
		}
		if(cnt<m) continue;
		for(int j=1;j<=n;++j){
			if(f[j]==0) ky[j]=0;
		}
		ans+=poww(i);
	}
	printf("%lld",ans);
	return 0;
}
