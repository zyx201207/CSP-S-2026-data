#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 7;
ll n,m,c;
ll q[MAXN];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&q[i]);
	}
	sort(q+1,q+n+1,cmp);
	int l=1,r;
	ll ans=-1;
	ll now=2;
	ll sum=0;
	for(int r=2;r<=n;r++){
		sum+=(q[r]-q[r-1])*now;
		now++;
		while(sum>m){
			sum-=(q[r]-q[l]);
			l++;
			now--;
		}
		ans=max(now,ans);
	}
	printf("%d",ans);
	return 0;
}