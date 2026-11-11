#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
bool vis[2000005];
vector<int> ans;
int n,d,minn = LLONG_MAX;
void dfs(int end,int cur,int len){
	if(cur == end){
		minn = min(minn,len + 1);
		ans.push_back(len + 1);
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(abs(x[i] - x[cur]) <= d && vis[i] == 0){
			vis[i] = 1;
			dfs(end,i,len + 1);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans.clear();
				dfs(j,i,0);
				int cnt1 = 0;
				for(int k = 0;k <= ans.size();k++){
					if(ans[k] == minn) cnt1++;
//					cout << minn << ' ' << ans[k] << ' ';
				} 
//				cout << endl;
				if(cnt1 == 2) cnt++;
			} 
		}
		cout << cnt << endl;
	}
	return 0;
}

