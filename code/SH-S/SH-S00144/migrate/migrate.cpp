#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+9,INF = 1e18;
ll c,t;
ll n,d;
ll a[N];
ll mn = INF,cnt = 0;
bool use[N];
void dfs(ll x,ll r,ll lst,ll num){
	if(x > r){
		if(num-1 < mn){
			mn = num-1,cnt = 1;
		}
		else cnt++;
		return;
	}
	if(a[x]-a[lst]>d)return;
//	if(num-1>mn)return;
	if(x == r){
		use[x] = 1;
		dfs(x+1,r,x,num+1);
		return;
	}
	use[x] = 1;
	dfs(x+1,r,x,num+1);
	use[x] = 0;
	dfs(x+1,r,lst,num);
}
void solveDFS(){
	ll ans = 0;
	for(ll i = 1;i <= n-2;i++){
		for(ll j = i+2;j <= n;j++){
			mn = INF,cnt = 0;
			for(ll i = 1;i <= n;i++)use[i] = 0;
			dfs(i+1,j,i,1);
			//cout << i << " to " << j << endl; 
			//cout << cnt << ' ' << mn << endl;
			if(cnt == 2)ans++;
		}
	}
	cout << ans << endl;
}
void solveA(){
	ll dis = a[2]-a[1];
	if(dis>d){
		printf("0\n");
		return;
	}
	ll css = d/dis;
	if(css == 1){
		printf("0\n");
		return;
	}
	printf("%lld\n",max(0LL,n-css*2+1));
}
void solveBF(){
	ll ans = 0;
	a[n+1] = INF;
	for(ll i = 1;i <= n-3;i++){
		ll mx = upper_bound(a+1,a+n+1,a[i]+d)-a;
		mx--;
		ll mxval = a[mx-1]+d;
		ll mnval = a[mx-2]+d;
		ll mxid = upper_bound(a+1,a+n+1,mxval)-a-1;
		ll mnid = upper_bound(a+1,a+n+1,mnval)-a;
		if(mnid-i<=2)mnid = i+3;
		if(mxid>n)mxid = n;
		if(mnid>n)mnid = n+1;
		//a[i]~a[i]+d 
		//cout << mx << ' ' << mxval << ' ' << mnval << ' ' << mxid << ' ' << mnid << endl;
		ans += max(0LL,mxid-mnid+1);
	}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;	
	while(t--){
		cin >> n >> d;
		for(ll i = 1;i <= n;i++)scanf("%lld",&a[i]);
		if(c == 11 || c == 12)solveA();
		else if(n <= 10)solveDFS();
		else solveBF();
	}
	return 0;
}

