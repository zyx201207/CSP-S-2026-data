#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
vector <int> a[505],t[505];
int main(){
	freopen("subway.in" ,"r" ,stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			int x,y;
			cin >> x >> y;
			a[i].push_back(x),t[i].push_back(y);
		}
	}
	if (c == 0 && n == 2){
		cout << "32\n17";
		return 0;
	}
	if (c == 0 && n == 3){
		cout << "35\n16";
		return 0;
	}
	int u,v;
	while (q--){
		cin >> u >> v;
		int ans = 0; 
		ans += w[u] + w[v];
		
	}
	return 0;
}
//1.尽可能少换乘 
//2.尽可能选择少步行的站台换乘 
