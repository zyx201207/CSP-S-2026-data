#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
int fpow(int ds,int cs){
	if (cs == 0) return 1;
	if (cs == 1) return ds;
	if (cs % 2 == 1) return fpow(ds,cs / 2) * fpow(ds,cs / 2) * ds;
	else return fpow(ds,cs / 2) * fpow(ds,cs / 2);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int maxi = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		maxi = max(maxi,a[i]);
	}
	int l = 0;
	while (fpow(2,l) <= maxi) l++;
	l--;
	vector<int> f;
	while ((f.size() > m || f.size() == 0) && l >= 0){
		vector<int> g;
		if (f.size() == 0){
			int sum = 0;
			int nl = fpow(2,l);
			for (int j = 1;j <= n;j++){
				if ((a[j] & nl) == nl) sum++;
			}
			if (sum >= m){
				for (int j = 1;j <= n;j++){
					if ((a[j] & nl) == nl) g.push_back(a[j]);
				}
			}
		}
		else{
			int sum = 0;
			int nl = fpow(2,l);
			for (int i = 0;i < f.size();i++){
				if ((f[i] & nl) == nl) sum++;
			}
			if (sum >= m){
				for (int i = 0;i < f.size();i++){
					if ((f[i] & nl) == nl) g.push_back(f[i]);
				}
			}
		}
		if (g.size() == 0 && f.size() != 0) break;
		else f = g;
		l--;
	}
	int ans = fpow(2,31) - 1;
	for (int i = 0;i < f.size();i++) ans = (ans & f[i]);
	cout << ans;
	return 0;
}//AFO. 100 + 56 + 100!!??(ying gai hui gua fen) + ? = 256? + ?

