#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200011],c[200011];
long long ma = -1;
inline void dfs(int i,int sum){
	if(i > n){
		if(sum == m){
			long long ans = 0,id = 0;
			for(int i = 1;i <= n;i++)
				if(c[i] == 1){
					ans = a[i],id = i;
					break;
				}
			for(int i = 1;i <= n;i++){
				if(c[i] == 1&&i != id)
					ans &= a[i];
			}
			ma = max(ma,ans);
		}
		return;
	}
	c[i] = 0;
	dfs(i + 1,sum);
	c[i] = 1;
	dfs(i + 1,sum + 1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	if(m == 2){
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				ma = max(a[i] & a[j],ma);
		printf("%lld\n",ma);
		return 0;
	}
	dfs(1,0);
	printf("%lld\n",ma);
	return 0;
}
