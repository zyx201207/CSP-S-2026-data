#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,c,T,k,a[N],b[N];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> k;
		for(int i = 1; i <= n ; i++){
			cin >> a[i];
		}
		if(n <= 5){
			cout << k - 1;
		}
		
	}
	return 0;
}

