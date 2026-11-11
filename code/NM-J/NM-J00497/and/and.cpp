#include<bits/stdc++.h>
using namespace std;
int n, m;
#define ll long long 
ll a[200005], t[200005];
ll ans, x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(ll i = 1; i <= n; i++){
		scanf("%d", &a[i]);	
	}
	sort(a+1, a+1+n);
	ll ans = a[n];
	for(ll i = n-1; i >=n-m+1; i--){
		ans = (ans)&(a[i]);
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
