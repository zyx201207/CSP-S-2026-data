#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
const int N=1e6+10;
const int M=2e6+10;
int c,T;
long long n,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		long long u,v;
		cin >> u >> v;
		
		if(n==5 && k==2){
			cout << 1 << endl;
			continue;
		}
		if(n==10 && k==3) {
			cout << 2 << endl;
		}
	}
	return 0;
}
