#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5, N=505;
int w[M], k[N], x[N], y[N], ti[N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		ti[i]=0;
		vector<int> a(k[i]+5);
		vector<int> t(k[i]+5);
		for(int j=1;j<=k[i];j++){
			cin >> a[j] >> t[j];
			ti[i]+=t[j];
			if(t[j]>50){
				ti[i]-=t[j];
			}
		}
	}
	for(int r=1;r<=q;r++){
		cin >> x[r] >> y[r];
	}
	for(int i=1;i<=n;i++){
		ti[i]+=ti[i-1];
	}
	for(int i=n;i>=n-q+1;i--){
		cout << ti[i] << '\n';
	}
	return 0;
}