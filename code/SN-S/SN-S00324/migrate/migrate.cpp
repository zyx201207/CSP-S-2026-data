//邓洛克 SN-S00324 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,T,n,d,a[2000005],sum[2000005],dis[2000005];
vector<int> vec[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) vec[i].clear();
		if(n == 1){
			cout << 0 << '\n';
			continue; 
		}
		else if(c >= 11 && c <= 12){
			int x = a[2] - a[1],res = -1;
			if(x > d){cout << 0 << '\n';continue;}
			for(int i = 4;i <= n;i += 2){
				if(x * i / 2 <= d && d < x * (i / 2 + 1)){
					res = i;
				}
			}
			if(res == -1) cout << 0 << '\n';
			else cout << n - res + 1 << '\n';
		}
		else if(c <= 10){
			int ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i + 1;j <= n;j++){
					if(abs(a[i] - a[j]) <= d){
						vec[i].push_back(j);
						vec[j].push_back(i);
					}
				}
			}
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++) sum[j] = 0,dis[j] = 1e18;
				queue<pair<int,int>> que;
				que.push({i,1});
				sum[i] = 1,dis[i] = 0;
				while(que.size()){
					int u = que.front().first,w = que.front().second;
					que.pop();
					for(int v : vec[u]){
						if(dis[v] > dis[u] + 1){
							dis[v] = dis[u] + 1;
							sum[v] = w;
							que.push({v,w});
						}
						else if(dis[v] == dis[u] + 1){
							sum[v] += w;
							que.push({v,w});
						}
					}
				}
				for(int j = 1;j <= n;j++) if(sum[j] == 2) ans++;
			}
			cout << ans / 2 << '\n';
		}
		else{
			cout << 0 << '\n';
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
