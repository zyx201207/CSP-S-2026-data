#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=1,R=i,Mid;
		while(L<R){
			Mid=(L+R)>>1;
			if(a[i]*(i-Mid+1)-(s[i]-s[Mid-1])<=m) R=Mid;
			else L=Mid+1;
		}
		if(a[i]*(i-R+1)-(s[i]-s[R-1])<=m) ans=max(ans,i-R+1);
	}
	printf("%d\n",ans);
	return 0;
}
