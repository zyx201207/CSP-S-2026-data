#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, x[2000005], sum[2000005], cnt[2000005], ct, ans;
bool flag[2000005];
vector<int> v[2000005];
queue<int> q;
void dfs(int id, int tx, int ex){
	if(id > sum[ex]) return ;
	if(id == sum[ex]){
		if(tx == ex){
			ct++;
		}
		return ;
	}
	for(auto xx : v[tx]){
		if(!flag[xx]){
//			cout << tx << ' ' << xx << endl;
			flag[xx] = true;
			dfs(id+1, xx, ex);
			flag[xx] = false;
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(x[j] - x[i] > d)
					break;
				v[i].push_back(j);
			} 
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			memset(cnt, 0, sizeof(cnt));
			memset(sum, 0x3f, sizeof(sum));
			memset(flag, 0, sizeof(flag));
			sum[i] = 0;
			q.push(i);
			while(!q.empty()){
				int t = q.front();
				q.pop();
				for(auto xx : v[t]){
					sum[xx] = min(sum[xx], sum[t]+1);
					if(!flag[xx]){
						q.push(xx);
						flag[xx] = true;
					}
				}
			}
//			for(int i = 1; i <= n; i++)
//				cout << sum[i] << ' ';
//			cout << i << endl;
			
			for(int j = i+1; j <= n; j++){
				ct = 0;
				memset(flag, 0, sizeof(flag));
//				cout << j << endl;
//				cout << i << ' ' << j << ' ' << sum[j] << ' ';
				dfs(0, x[i], x[j]);
//				cout << ct;
				if(ct == 2 && sum[j] > 1){
//					cout << "asdf " << i << ' ' << j << ' ' << sum[j] << ' ' << ct << '\n';
					ans++;
				}
//				cout << endl;
			}
		}
		cout << ans << '\n';
//		cout << endl;
	}
	return 0;
}
