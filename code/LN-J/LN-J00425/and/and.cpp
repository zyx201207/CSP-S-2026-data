#include <bits/stdc++.h>

int dfs(std::vector<int>& arr, int m, std::vector<int>& chosen, int depth=0, int mn=0){
	if (depth == m){
		int now = chosen.front();
		for (int i=1;i<m;i++){
			now&=chosen[i];
		}
		return now;
	}
	int max=0;
	for (int i=mn;i<(int)arr.size();i++){
		chosen[depth] = arr[i];
		max = std::max(dfs(arr, m, chosen, depth+1, i+1), max);
	}
	return max;
}

int main(void){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	std::cin>>n>>m;
	std::vector<int> arr(n), chosen(m);
	for (int& i: arr) std::cin>>i;
	std::cout<<dfs(arr, m, chosen);
}
