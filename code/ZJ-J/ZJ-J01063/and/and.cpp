#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool can(int x){
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if((a[i] & x) == x) cnt++;
	}
	return cnt >= m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	int ans = 0;
	for(int i = 29;i>=0;i--){
		if(can(ans + (1 << i))){
			ans += (1 << i);
		}
	}
	printf("%d",ans);
	return 0;
}
