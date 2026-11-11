#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >>n >> m >> d >> q;
	int a[N];
	for(int i=1;i<=m;i++) cin >> a[i];
	vector<int> e[N];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;i<=k;j++){
			int x,w;
			cin >> x >> w;
			e[i].push_back(w);
		}
	}
	while(q--){
		int r,c;
		cin >> r >>c;
		cout << a[r]+a[c]+e[(r+c)/2][0]+e[(r+c)/2][1] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
