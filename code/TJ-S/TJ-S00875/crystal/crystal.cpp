#include <cstdio>
#include <algorithm>
const long long MAXN=100000000;
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(&a[1],&a[n+1]);
	for(int i=2;i<=n;){
		if(a[i+1]-a[i]<=m){
			m-=a[i+1]-a[i];
			a[i]=a[i+1];
			if(a[i]!=a[i-1]&&i>=2&&m>0){
				i--;
			}else{
				if(m<=0) break;
				else i++;
			}
		}else{
			break;         	
		}
	}
	int c=1;
	for(int i=1;i<=n-1;i++){
		if(n==1){
			c=1;	
		}else{
			if(a[i]==a[i+1]) c++;
		}
	}
	printf("%d\n",c);
	return 0;
}
