#include<bits/stdc++.h>
using namespace std;
long long n,m,p=1,nm,ans,a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>1) nm+=(i-p)*(a[i]-a[i-1]);
		while(nm>m){
			nm-=a[i]-a[p];
			p++;
		}
		ans=max(ans,i-p+1);
	} 
	printf("%lld\n",ans);
	return 0;
}
