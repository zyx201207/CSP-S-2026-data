#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		cout<<n/d;
	}
	return 0;
}
