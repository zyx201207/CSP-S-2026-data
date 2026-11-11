#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,_; 
int n,d;
int x[N];
int ans;

void solve(){
	cin>>n>>d;
	if(n==1){
		cout<<0<<endl;
		return;
	}
	for(int i=1; i<=n; i++)cin>>x[i];
	ans=n/d;
	if((n%d)%2==0)ans--;
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--){
		solve();
	}
	return 0;
}
//神兽保佑，代码无bug!!!
