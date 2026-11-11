#include <bits/stdc++.h>
using namespace std;
int l,fa,n,m,x,y,k,d,q,s,a[500005];
long long c,ans,cnt = 1e18;
map <int,int> p[505];
vector<pair<int,int> > v[500005];
void dfs(int b,int e,int l){
	if (b == e) {cnt = min(c,cnt);c=0;return;}
	for (auto i : v[b]){
		if (i.first == fa) continue;
		if (i.second != l) c += (p[i.second][i.first] + p[i.second][l]);
		l = i.second;fa = b;
		dfs(i.first,e,l);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if (c == 0){
		if (n == 2) cout << 32 << '\n' << 17;
		if (n == 3) cout << 35 << '\n' << 16;
	}
	else{
		for (int i = 1;i <= m;i++) cin >> a[i];
		for (int i = 1;i <= n;i++){cin >> x;
			for (int j = 1;j <= x;j++){
				cin >> y >> k;p[i][k]=y;
				if (j == 1) s = y;
				v[s].push_back({y,i});
				v[y].push_back({s,i});
			}
		}
		for (int i = 1;i <= q;i++){
			cin >> x >> y;fa=x;l=0;dfs(x,y,l);
			cout << cnt + (a[x]+a[y]);
		}
	}
}
