#include<iostream>
using namespace std;
int sum = 0;
vector<int> g[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i)	
		cin >> w[i];
	for(int i=1;i<=n;++i){
		int k; cin >> k;
		for(int j=1;j<=k;++j){
			cin >> a[i][j] >> t[i][j];
			for(int kk=1;kk<=k;++kk)
				if(a[kk][j] == a[i][j]) g.[kk].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		sum += w[x] + w[y];
		int now = g.front();
		
	}
	cout << sum;
	return 0;
}
