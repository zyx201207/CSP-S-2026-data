#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 1000;
bool vis[N][32];
int cnt[32];
int a[N];
vector<int> g[32];
vector<int> bx;
int ans;
vector<int> won,fil;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		for(int j = 30;j >= 0 ;j--){
			if(( 1 << j) & a[i]){
				vis[i][j] = true;
				cnt[j]++;
				g[j].push_back(i);
			}
		}
	}

	int p = 31;
	while(cnt[p] < m) p--;
	ans += (1 << p);
	for(int v : g[p]){
		bx.push_back(v);
	}
	for(int i = p - 1;i >= 0;i--){
		if(cnt[i] < m) continue;
		won.clear();
		fil.clear();
		int sum = 0;
		for(int v : bx){
			if(vis[v][i]) won.push_back(v);
			else fil.push_back(v);
		}
		if(won.size() < m) continue;
		else{
			bx.clear();
			for(int v : won){
				bx.push_back(v);
			}
			ans += (1 << i);
		}
	}
	cout << ans;
	return 0;
}
