#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const int MAXM = 1e5 + 10;

bool vis[MAXM]; 
int ip[MAXN];
int q[MAXN];

int a[MAXN]; 

int ans[MAXM];

int n;
int m;

int main(){
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++ i){
		cin >> a[i];
	}
	
	for(int id = 1; id <= n; ++ id){
		memset(vis, 0, sizeof vis);
		memset(ip, -1, sizeof ip);
		int cnt;
		cnt = 0;

		for(int i = id; i <= n; ++ i){
			if(vis[a[i]]){
				int o;
				o = ip[a[i]];
				for(int j = o + 1; j <= cnt; ++ j){
					vis[q[j]] = 0;
					ip[q[j]] = -1;
					ans[q[j]] --;
				}
				cnt = o;
			}else{
				vis[a[i]] = 1;
				cnt ++;
				q[cnt] = a[i];
				ip[a[i]] = cnt;
				ans[a[i]] ++;
			}
		}
		/*
		for(int i = id; i <= n; ++ i){
			if(ip[a[i]] != -1){
				ans[a[i]] ++;
			}
		}*/
//		cout << ans << " ";
	}
	
	for(int i = 1; i <= m - 1; ++ i){
		cout << ans[i] << " ";
	}
	cout << ans[m]; 
	
	return 0;
} 
