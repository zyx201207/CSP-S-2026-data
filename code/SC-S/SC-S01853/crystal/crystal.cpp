#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll n,m;
ll a[N],b[N],pre[N];

bool check(ll x){
	for (int l=1;l+x-1<=n;l++){
		int r=l+x-1;
		if (pre[r]-pre[l-1]-b[r]*x<=m)
			return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		b[i]=pre[i]=a[n]-a[i];
		pre[i]+=pre[i-1];
	}
	ll l=1,r=n;
	while (l<r){
		ll mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}