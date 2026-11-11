#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
template <typename T >bool relax(T &a,const T &b){return b>a?a=b,true:false;}
template <typename T >bool tense(T &a,const T &b){return b<a?a=b,true:false;}
const int N=500005;
int n;
long long m;
long long a[N],s[N];
int t=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(1ll*(i-j+1)*a[i]-(s[i]-s[j-1])>m) j++;
		relax(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;	
}
