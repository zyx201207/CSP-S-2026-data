#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500010];
int ans=1,k=0,rst;
int maxx=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1;
	rst=m;
	for(int i=2;i<=n;i++){
		while(rst<ans*(a[i]-a[i-1])){
			k-=a[i-1]-a[l];
			rst+=a[i-1]-a[l];
			ans--;
			l++;
		}
		rst-=ans*(a[i]-a[i-1]);
		k+=ans*(a[i]-a[i-1]);
		ans++;
		maxx=max(maxx,ans);
		//printf("i:%lld k:%lld rst:%lld max:%lld\n",i,k,rst,maxx);
	}
	printf("%lld\n",maxx);
	return 0;
}
