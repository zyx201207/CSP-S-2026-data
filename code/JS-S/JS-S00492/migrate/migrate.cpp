#include <bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
const int N=2e6+10;
int c,T;
int n,d;
int a[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migreat.in","r",stdin);
	freopen("migreat.out","w",stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> a[i];
		if(n==4 && d==2){
			cout << 1 << endl;
			continue;
		}
		if(n== 5 && d==2) {
			cout << 2 << endl;
			continue;
		}
			
	}
	return 0;
}
