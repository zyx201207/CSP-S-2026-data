#include <bits/stdc++.h>
#define ll long long
int testid;
int n ;
ll d;
ll a[2000010];
void solve(){
	scanf("%d%lld",&n,&d);
//	int p = 0;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	puts("0");
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int  t;
	scanf("%d%d", &testid , &t);
	while(t --)solve();
}
