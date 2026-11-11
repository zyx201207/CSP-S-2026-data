#include <bits/stdc++.h>
using namespace std;
long long n,ans,m,a[200010],b[200010];
inline void dfs(int x,long long an){
//	printf("	%d %d\n",x - 1,an);
	if(x == m + 1){
		ans = max(ans,an);
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!b[i]){
			if(an){
				int an1 = an & a[i];
				b[i] = 1;
				dfs(x + 1,an1);
				b[i] = 0;
			}
			else{
				b[i] = 1;
				dfs(x + 1,a[i]);
				b[i] = 0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i++)
			ans &= a[i];
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
}
