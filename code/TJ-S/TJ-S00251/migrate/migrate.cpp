#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+25;

int C;
ll n,d;
ll dgr[N];

void solve(){
	cin>>n>>d;
//	cout<<n<<" "<<d<<" "; 
	for (int i=1;i<=n;++i) cin>>dgr[i];
	if (n==1){
		cout<<0<<'\n';
		return;
	}
//	if (C==11 || C==12){
		ll D=dgr[2]-dgr[1];
		if (d<D*2){
			cout<<0<<'\n';
			return;
		}
		ll k=d/D;
//		cout<<D<<" "<<k<<" ";
		cout<<max(0ll,n-k-1)<<'\n';
		return;
//	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>C>>T;
	while (T--) solve();
	return 0;
}//migrate
