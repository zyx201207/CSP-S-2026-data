#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005],s[500005],n,m;
inline int& minn(int & a,int b){
	if(a>b) a=b;
	return a;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long need=0,ans=0,l=1;
	for(int i=1;i<=n;i++){
		while(l<i&&a[i]*(i-l+1)-(s[i]-s[l-1])>m) l++;
		if(ans<i-l+1)ans=i-l+1;
	}
	printf("%lld",ans);
	return 0;
} 
