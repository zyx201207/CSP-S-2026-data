#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll c,dy[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll T;
	cin >> c >> T;
	while(T --){
		ll n,d;
		cin >> n >> d;
		memset(dy,0,sizeof(dy));
		for(int i = 1;i <= n;i ++) cin >> dy[i];
		cout << n - 1 << endl; 
	}	
	return 0;
}
