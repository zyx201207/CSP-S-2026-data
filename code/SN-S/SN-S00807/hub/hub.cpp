#include <bits/stdc++.h>
#define int long long
using namespace std;
int u[1000005],v[1000005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >>k;
		for(int i=1;i<n;i++){
			cin >>u[i] >> v[i];
		}
	}
	return 0;
}  
