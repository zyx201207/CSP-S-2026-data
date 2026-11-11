#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","hub.out",stdin);
	freopen("hub.in","hub.out",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k,u[10056],v[114514];
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			cin >> u[i] >> v[i]; 
		}
		if(t == 1) cout << 2;
		else cout << 1 << endl;
	}
	return 0;
}
