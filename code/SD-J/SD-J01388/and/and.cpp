#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int ans = 0;
int lowbit(int x){
	return x & (-x);
}
int log_2(int x){
	if(x == 1)return 0;
	int flag = 2;
	for(int i = 1; i <= 35; i++){
		if(flag == x)return i;
		flag *= 2;
	}
	return 0;
}
int vist[35];
void dfs(vector<int> v){
	if(v.size() == 0)return;
	int vis[35];
	for(int i = 0; i <= 34; i++){
		vis[i] = 0;
	} 
//	unordered_set<int> s;
	int man = 0;
	int power = 0;
	for(auto tar : v){
		while(tar){
			int low = lowbit(tar);
	//		cout << low << endl;
			man = max(man, log_2(low));
			vis[log_2(low)]++;
			tar -= low;
		}
	}
	vector<int> v1;
	int flag = -1;
	for(int i = man; i >= 0; i--){
	//	cout << vis[i] << endl;
		if(vis[i] >= m && vist[i] == 0){
			flag = i;
			break;
		}
	}
//	cout << flag << ' ';
	if(flag == -1)return;
	int newn = 1;
	for(int i = 1; i <= flag; i++){
		newn *= 2;
	}
	
	for(auto tar : v){
		if(tar & newn)v1.push_back(tar);
	}
	if(v1.size() == 0)return;
	vist[flag] = 1;
//	cout << newn << endl;
	ans += newn;
	dfs(v1);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vector<int> v;
	int maxn = 0;
	for(int i = 1, x; i <= n; i++){
		cin >> x;
		maxn = max(maxn, x);
		v.push_back(x);
	}
	dfs(v);
	cout << ans;
	return 0;
}
