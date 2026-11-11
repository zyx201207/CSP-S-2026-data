#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,ans,p;
long long m,a[N],s[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) {
		if(p<i) p=i;
		while(p<=n&&a[p]*(p-i)-(s[p-1]-s[i-1])<=m) ++p;
		ans=max(ans,p-i);
	}
	printf("%d\n",ans);
	return 0;
}
/*
ÓÎ¼Ç£ºhttps://www.luogu.com.cn/article/vo1uk7d5
orange
*/
