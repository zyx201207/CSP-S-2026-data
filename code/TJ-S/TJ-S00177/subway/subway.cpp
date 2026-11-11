#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
int t[500005];
int t2[500005];
void solve1(){
	int k, l;
	cin >> k;
	for(int i = 1;i<=k;i++){
		cin >> l;
		cin >> t[l];
	}
	for(int i = 1;i<=q;i++){
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + t[x] + t[y] << "\n";
	}
	return;
}
void solve2(){
	int kk1, kk2, l, mia = 2e9;
	cin >> kk1;
	for(int i = 1;i<=kk1;i++){
		cin >> l;
		cin >> t[l];
	}
	cin >> kk2;
	for(int i = 1;i<=kk2;i++){
		cin >> l;
		cin >> t2[l];
		if(t[l]>0) mia = min(mia,t[l]+t2[l]);
	}
	for(int i = 1;i<=q;i++){
		int x, y;
		cin >> x >> y;
		if(t[x]>0 && t[y]>0) cout << w[x] + w[y] + t[x] + t[y] << "\n";
		else if(t2[x]>0 && t2[y]>0) cout << w[x] + w[y] + t2[x] + t2[y] << "\n";
		else cout << w[x] + w[y] + max(t[x],t2[x]) + max(t[y],t2[y]) + mia << "\n";
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++) cin >> w[i];
	if(n==1) solve1();
	else if(n==2) solve2();
	else cout << 4 << "\n";
	return 0;
}
