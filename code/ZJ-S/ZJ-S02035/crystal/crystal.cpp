#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500010;
int n;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];
	int l=1,ans=0;
	for(int r=1;r<=n;++r){
		while(l<r&&
		a[r]*(r-l+1)-(s[r]-s[l-1])>m)++l;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
