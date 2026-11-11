#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
ll n,d,q,w;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		int y;
		cin>>n>>d>>q>>w;
		for(ll i=1;i<=n-2;i++)cin>>y;
		ll g=w-q;
		ll p=d/g;
		if(p==1||g>p){
			cout<<0<<endl;
			continue;
		}
		cout<<n-2*p+1<<endl;
	}
	return 0;
}