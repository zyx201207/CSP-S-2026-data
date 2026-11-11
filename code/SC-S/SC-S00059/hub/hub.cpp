#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,T;
int n,k;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin >> u >> v;
		}
		if(k==n){
			cout << 0 << endl;
			continue;
		}
		if(k>=n/2){
			cout << 1 << endl;
			continue;
		}
		
		int tmp=(n-1)/2-k-1;
		cout << tmp/4+2 << endl;
	}
	return 0;
}