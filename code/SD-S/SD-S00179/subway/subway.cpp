#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
vector<int> a[505],t[505];
int minans = LLONG_MAX;
void dfs(int end,int cur,int sum){
	if(cur == end){
		minans = min(minans,sum);
		return ;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	int sumt = 0;
	for(int i = 1;i <= n;i++){
		int K;
		cin >> K;
		for(int j = 1;j <= K;j++){
			int aa,tt;
			cin >> aa >> tt;
			sumt += tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x] + w[y] + sumt << endl;
	}
	return 0;
}

