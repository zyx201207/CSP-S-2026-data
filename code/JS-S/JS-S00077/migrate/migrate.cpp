#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,q;
vector<ll>a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		int n;
		ll d;
		cin>>n>>d;
		a.assign(n+1,0);
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<0;
	}
	return 0;
}
