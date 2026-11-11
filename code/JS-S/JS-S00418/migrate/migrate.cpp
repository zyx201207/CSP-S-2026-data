#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	ll d;
	cin>>n>>d;
	vector<ll> x(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=0;
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
