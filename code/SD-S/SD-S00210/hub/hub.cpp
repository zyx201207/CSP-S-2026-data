#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i++){
			int x,y;
			cin >> x >> y;
		}
		if(k>=n){
			cout << 0 << '\n';
			continue;
		}
		n = n/2+1;
		if(k>=n-1){
			cout << 1 << '\n';
			continue;
		}
		cout << ceil((n-k+3)/4.0) << '\n';
	}
	return 0;
}

