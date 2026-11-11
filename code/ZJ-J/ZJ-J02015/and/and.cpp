#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],m,vis[200010];
long long x,y;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",n,m);
	for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
	long long ans = 0;
	if(m = n){
		ans = a[1];
		for(int i = 2;i<=n;i++)ans = ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m ==1){
		for(int i = 1;i<=n;i++)ans = max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	for(int i = n;i>=1;i--){
		for(int j = 1;j<=i;j++){
			if(a[i]&a[j]>ans){
				ans = a[i]&a[j];
				x = i;
				y = j;
			}
		}
	}
	if(m==2){
		cout<<ans;
		return 0;
	}
	vis[x] = 1;
	vis[y] = 1;
	for(int i = 2;i<=m;i++){
		long long z = 0;
		for(int j = 1;j<=n;j++){
			if(vis[i]==1)continue;
			if((ans&a[i])>ans){
				ans = ans&a[i];
				z = i;
			}
		}
		vis[z] = 1;
	}
	cout<<ans;
	return 0;
}
