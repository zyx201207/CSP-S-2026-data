#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0,i=n,j=n;
	while(j>0&&i>0){
		while(j>0&&m>=a[i]-a[j]){
			m-=a[i]-a[j];
			j--;
		}
		ans=max(ans,i-j);
		i--;
		m+=(i-j)*(a[i+1]-a[i]);
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

/*
15min good
*/
