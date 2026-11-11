#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , m , ans , vis[200005] , a[200005] ;
void dfs(int k , int x , int sum){
	if(k==m){
		ans=max(ans,sum);
		// cout << "\n" ;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			// cout << i << "* " ;
			dfs(k+1,i,sum&a[i]);
			vis[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		printf("%lld",ans);
		return 0;
	}else if(m==2&&n<=10000){
		cout << 1 ;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		printf("%lld",ans);
		return 0;
	}else if(n<=20){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(1,i,a[i]);
			vis[i]=0;
		}
		printf("%lld",ans);
		return 0;
	}
	else printf("%lld",a[n-m+1]);
	return 0;
}