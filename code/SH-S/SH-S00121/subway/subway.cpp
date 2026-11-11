#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define int unsigned int
using namespace std;
typedef pair<int,int> pii;
int n,m,c,d,q;
int t[505][505],r;
vector<int> e[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> t[i];
	for(int i = 1;i <= m;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int u;
			cin >> u >> r;
			e[u].push_back(i);
		}
	}
	while(q--){
		int a,b;
		cin >> a >> b;
		if(a == b){
			cout << a + b << endl;
			continue;
		}
		cout << 2 * r + a + b << endl;
	}
}
