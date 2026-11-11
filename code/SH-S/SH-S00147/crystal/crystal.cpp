#include <bits/stdc++.h>
using namespace std;

typedef long long LL; 

const int N = 500005;

int n, ans;
LL m;

LL a[N];
LL d[N];

deque<int> q;

bool is_dengcha(){
	LL df = a[2] - a[1];
	for (int i = 2; i <= n; i++){
		if (a[i] - a[i - 1] != df) return false;
	}
	
	return true;
}

void solve_A(){
	// 对于等差数列可以从后往前
	for (int i = n; i >= 1; i--){
		LL df = a[n] - a[i];
		if (m >= df){
			m -= df;
			ans++;
		} else {
			break;
		}
	}
}

void solve_baoli(){
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++){  // 枚举基准，然后从它之前不断加 
		int cnt = 0;
		LL m2 = m;	
		for (int j = i; j >= 1; j--){
			LL di = a[i] - a[j];
			if (m2 >= di){
				m2 -= di;
				cnt++;
			} else {
				break;
			}	
		}
		ans = max(ans, cnt);
	}
}

bool check_if_works(int st, int ed){
	LL m2 = m;
	for (int j = ed; j >= st; j--){
		LL di = a[ed] - a[j];
		if (m2 >= di){
			m2 -= di;
		} else {
			return false;
		}	
	}
	
	return true;
}

void solve_baoli_2(){
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++){  // 枚举基准，然后从它之前不断加 
		while (!check_if_works(q.front(), i)) q.pop_front();
		q.push_back(i);
		int ed = q.back();
		int cnt = 0;
		LL m2 = m;
		for (auto j : q){
			LL di = a[ed] - a[j];
			if (m2 >= di){
				m2 -= di;
				cnt++;
			} else break;
		}
		
		ans = max(ans, cnt);
	}
}

int main(){
	// 不要忘了解开注释！！！！！ 
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	if (is_dengcha()) solve_A();
	else {
		if (n <= 5000){
			solve_baoli_2();
		} else {
			solve_baoli_2();
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
