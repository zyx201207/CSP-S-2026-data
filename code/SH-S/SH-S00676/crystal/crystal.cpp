#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

const int maxn = 5e5 + 15;
ll n,m,a[maxn],sum[maxn],ans = 1;
void input(){
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
}
ll get_sum(int l,int r){
	return sum[r] - sum[l - 1];
}
void test(int x){
	ll tar = a[x];
	int l = 1,r = x - 1;
	ll res = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		if(tar * (x - mid) - get_sum(mid,x - 1) <= m){
			r = mid - 1;
			res = x - mid + 1;
		}
		else{
			l = mid + 1;
		}
	}
	ans = max(ans,res);
}
void solve(){
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		test(i);
	}
	printf("%lld",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
