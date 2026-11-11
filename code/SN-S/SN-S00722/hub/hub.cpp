#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin >> u >> v; 
		}
		cout << k-2 << "\n";
	}
	
	return 0;
} 
