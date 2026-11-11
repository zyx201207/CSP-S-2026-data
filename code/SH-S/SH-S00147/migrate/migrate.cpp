#include <bits/stdc++.h>
using namespace std;

typedef long long LL; 

const int N = 2e6+10;

int c, T, n;
LL d;
LL a[N];
int ways;
int goal_steps;

bool is_dengcha(){
	LL df = a[2] - a[1];
	for (int i = 2; i <= n; i++){
		if (a[i] - a[i - 1] != df) return false;
	}
	
	return true;
}


void dfs(int cur_pos, int goal, int steps){
	if (cur_pos >= goal){
		if (steps == goal_steps){
			ways++;
		}
		return;
	}
	
	for (int i = cur_pos + 1; i <= goal; i++){
		if (a[i] - a[cur_pos] <= d){
			dfs(i, goal, steps+1);
		} else break;
	}
} 
 
int solve1(){  // 暴力 
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			ways = 0;
			
			// 判断sjdy
			int cnt = 0;  // 记录最少需要的步数 
			int k = i;
			while (k < j){  // 只要没到j就跳一次 
				int k = upper_bound(a + 1, a + n + 1, a[k] + d) - a;
				k--;
				cnt++;
			}
			
			goal_steps = cnt;
			dfs(i, k, 0);
			
			if (ways == 2){
				ans++;
			}
 		}
	}
	
	return ans;
}

int solve_dengcha(){
	int ans = 0;
	for (int i = 1; i <= n; i++){  // 枚举长度
		int diff = a[1 + i - 1] - a[1];
		if (d < diff && diff < 2 * d) ans += n - i + 1;
	}
	
	return ans;
}

int main(){
	// 不要忘了解开注释！！！！！ 
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> T;
	
	while (T--){
		ways= 0, goal_steps = 0, n = 0, d = 0;
		memset(a, 0, sizeof a);
		
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		if (is_dengcha()){
			cout << solve_dengcha() << endl;
		} else {
			if (n <= 300){
				cout << solve1() << endl;
			} else cout << 0 << endl;
		}

	}
	
	return 0;
}
