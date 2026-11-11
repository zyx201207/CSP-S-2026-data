#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		int n,d;
		cin>>n>>d;
		vector<int> v(n);
		for (auto &i:v) cin>>i;
		if (((v[1]-v[0])*2)<=d&&n>=4) cout<<n-3<<"\n";
		else cout<<0<<"\n";
	}
}
