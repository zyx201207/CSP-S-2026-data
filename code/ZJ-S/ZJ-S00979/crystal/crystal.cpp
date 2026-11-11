#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	long long j=n,now=0;
	sort(a+1,a+1+n);
	for(int i=n;i;i--){
		while(now+a[i]-a[j-1]<=m&&j-1>=1){
			now+=a[i]-a[j-1],j--;
		//	cout<<i<<" "<<j<<" "<<now<<"\n";
		}
		ans=max(ans,i-j+1),now-=(i-j)*(a[i]-a[i-1]);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/