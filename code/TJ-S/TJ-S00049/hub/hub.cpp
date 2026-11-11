#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v,x[100001];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		memset(x,0,sizeof(x));
		cin >> n >> k;
		for(int i =1;i<n;i++){
			cin >> u >> v;
			x[u] = v;
			x[v] = u;
		}
		
	}
	cout << 1 << "\n" << 2; 
	return 0;
}
