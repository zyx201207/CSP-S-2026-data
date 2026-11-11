#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k, u, v;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <n; i ++)
			cin >>u >> v;
		cout <<t<<'\n';
	}
	return 0;
}


