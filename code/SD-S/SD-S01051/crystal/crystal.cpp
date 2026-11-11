#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[500100],sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	int l=n+1;
	for(int r=n;r>=1;r--){
		while(l>1&&(r-l+2)*a[r]-(sum+a[l-1])<=m){
			l--;
			sum+=a[l];
		}
		ans=max(ans,r-l+1);
		sum-=a[r];
	}
	printf("%lld",ans);
	return 0;
}

