#include <bits/stdc++.h>
using namespace std;

const int maxn = 500001;
int s;

void sort(int a[maxn], int n) {	//排序
	for(int i = 2; i <= n; i++) { 
		for(int j = 1; j <= n; j++) {
			if(a[j] > a[i]) {
				s = a[i];
				a[i] = a[j];
				a[j] = s;
			} 
		}
	}
	return;
}

void reverse(int stay[maxn], int a[maxn], int n) {//让stay=a 
	for(int i = 1; i <= n; i++) {
		stay[i] = a[i];
	}
	return;
}

int get_max(int a[maxn], int n) {//获取最大水晶数 
	int ans;
	for(int i = 2; i <= n; i++) { 
		for(int j = 1; j <= n; j++) {
			if(a[j] > a[i]) {
				s = a[i];
				a[i] = a[j];
				a[j] = s;
			} 
		}
	}
	ans = a[n];
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr);
	
	int n, a[maxn], m, cnt = 0;
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}; //输入 
	
	int count_need[n], stay[n], max[n], queue_max[n], count, res[n];
	queue<int> times;
	
	sort(a, n);
	
	for(int i = 2; i <= n; i++) {//获取从a[2]开始的每一位所需的操作次数
		for(int j = 1; j <= i; j++) {
			cnt += a[i] - a[j];
		}
		count_need[i] = cnt;
		cnt = 0;
	} 
	
	for(int i = 1; i <= n; i++) {//获取所需操作次数不超过m的位数 
		if(count_need[i] <= m) {
			cnt++;
		}
	}

	
	for(int i = 2; i <= cnt; i++) {
		for(int j = 1; j <= i; j++) {
			if(i != j) stay[j] = stay[i];
		}
		
		for(int i = 1; i <= n; i++) { 
			count = 1;
			for(int j = 1; j <= n; j++) {
				if(i != j && stay[i] == stay[j]) count++;
			}
			res[i] = count;
			count = 0;
		}
		

		max[i] = get_max(res, cnt);
		reverse(stay, a, n);
	}
	
	cout << get_max(max, cnt);
	
	return 0;
} 

