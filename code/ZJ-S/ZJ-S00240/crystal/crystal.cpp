#include <bits/stdc++.h>
using namespace std;
typedef long long llg;
const int N = 5e5+10;
llg a[N];
llg b[N];
int c[N],l=1,r=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	llg m;
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ll=1,rr=1,ans = 1;
	while(rr<=n){
		while(l<r&&a[c[r-1]]<=a[rr]) r--;
		c[r++]=rr;
		llg k = a[c[l]]*(rr-ll+1)-(b[rr]-b[ll-1]);
		if(k>m){
			ll++;
		}else{
			ans = max(ans,rr-ll+1);
			rr++;
		}
		while(l<r&&c[l]<ll) l++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
