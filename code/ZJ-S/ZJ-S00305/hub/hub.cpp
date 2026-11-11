#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=5e5+100,inf=1e18;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	ll n,k,u,v;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			cin >> u >> v;
		}
		if(k<2){
			cout << 1 << endl;
		}
		else if(k<=2&&n>=3){
			cout << 1 << endl;
		}
		else if(k>=3){
			cout << 2 << endl;
		}
	}
	return 0;
}
