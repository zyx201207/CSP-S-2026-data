#include <iostream>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],f[N],cnt[N];
bool tsA=1;
void solveA(){
	for(int i=1;i<=n;++i){
		if(a[i+1]!=a[i]) printf("%lld ",i);
	}
}
void solve2(){
	int cntt=0;
	if(a[n]==1){
		for(int i=1;i<=n;++i){
			if(a[i]==2) cntt++;
		}
		printf("%lld %lld",n,cntt);
	}
	else{
		for(int i=1;i<=n;++i){
			if(a[i]==1) cntt++;
		}
		printf("%lld %lld",cntt,n);
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]) tsA=0;
	}
	if(tsA){
		solveA();
		return 0;
	}
	if(m<=2){
		solve2();
		return 0;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i) f[i]=a[i];
		for(int i=k;i<=n;++i){
			int tamp=f[i];
			for(int j=k;j<i;++j){
				if(f[j]==tamp){
					for(int pu=j;pu<i;++pu){
						f[pu]=0;
					}
					break;
				}
			}
		}
		for(int i=k;i<=n;++i){
			cnt[f[i]]++;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%lld ",cnt[i]);
	}
	return 0;
}
