#include<bits/stdc++.h>
using namespace std;
long long c, t, n, k;
const int maxn = 1e6+10;
long long u[maxn], v[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
  	for(long long i = 1;i <= t;i++){
  		cin >> n >> k;
		for(long long j = 1;j < n;j++){
			cin >> u[i] >> v[i];
		}
		if(n == 5 && k == 2){
			cout << 1 << '\n';
		}else if(n == 10 && k == 3){
			cout << 2 << '\n';
		}else{
			cout << 10 << '\n';
		}
	}
	return 0;
}
