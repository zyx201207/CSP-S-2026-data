#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 5e5 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
ll n,m,a[N],sum[N];
bool check(int x){
	for(int l = 1;l <= n - x + 1;l++){
		int r = l + x - 1;
		ll t = a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
		if(t <= m){
			return 1;
		}
	}
	return 0;
}
void work(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0,r = n + 1,mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	cout << l << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

