#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
using ll = long long;
int c,t;
int n;
ll m;
ll a[maxn];
void solve1(){
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if (n==1){
		cout<<"0\n";
		return;
	}
	ll d = a[n]-a[n-1];
	ll t = m/d;
	//i+t+k
	ll l = max(n-t-(t-1),0ll),r = max(n-t-1,0ll);
	cout<<(l+r)*(r-l+1)/2<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	if (c==11 || c==12){
		while (t--) solve1();
	}
	return 0;
}