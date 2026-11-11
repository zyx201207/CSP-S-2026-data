#include <cstdio>
#include <algorithm>
#include <map>

const int maxn=500005;

long long a[maxn];
int n;
long long m;

std::map<long long,int> c; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),c[a[i]]++;
	std::sort(a+1,a+n+1);
	
	int ans=0;
	for(int i=1;i<=n;i++){
		long long m0=m;
		int local=0;
		for(int j=i;j>=1;j-=c[a[j]]){
			long long cost=1ll*c[a[j]]*(a[i]-a[j]);
			if(m0>=cost) m0-=cost,local+=c[a[j]];
			else{
				local+=m0/(a[i]-a[j]);	
				break;
			}
		}
		if(ans<local) ans=local;
	}
	return 0;
}
