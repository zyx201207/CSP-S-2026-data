#include <bits/stdc++.h>
using namespace std;
int w[500010];
map<long long,map<long long,int> > a,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		int ans=0;
		ans+=w[x]+w[y];
		
		cout << ans << endl;
	}
	return 0;
}