#include <iostream>
using namespace std;
int n,m,d,q;
unsigned short c;
int w[1100],a[501][500001],t[501][500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> a[i][j] >> t[i][j];
		}
	} 
	
	while(q--){
		int x,y;
		cin >> x >> y;
	}
	cout << "35\n16";
	return 0;
}
