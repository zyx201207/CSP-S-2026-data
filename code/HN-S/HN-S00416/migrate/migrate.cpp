#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int s = a[2]-a[1];
	if(d<s*2){
		cout<<0<<'\n';
		return;
	}
	long long ans = 0;
	for(int i = 4;i<=n;i++){
		if(d>=a[i]-a[1]){
			cout<<0<<'\n';
			return;
		}
	}
	for(int i = 4;i<=n;i++){
		if(i%2==0)ans+=i/2;
	}
	if(n!=4)cout<<1<<'\n';
	else cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
