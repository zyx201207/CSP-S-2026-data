#include<bits/stdc++.h>
#define N ((int)()+10)
using namespace std;
using ll=long long;
const ll MOD=1e18+1;
mt19937_64 rd(time(0));
ll a[10010];
signed main(){
	freopen("migrate7.in","w",stdout);
	puts("0 1");
	puts("10000 2000000000000000000");
	for(int i=1;i<=10000;i++){
		a[i]=rd()%MOD;
		if(rd()&1)a[i]*=-1;
	}
	sort(a+1,a+10000+1);
	for(int i=1;i<=10000;i++)printf("%lld ",a[i]);
}

