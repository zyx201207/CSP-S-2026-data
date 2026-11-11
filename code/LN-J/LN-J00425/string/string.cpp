#include <bits/stdc++.h>

int main(void){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin>>n;
	std::vector<char> vec;
	while (n--){
		int a;
		char b;
		std::cin>>a>>b;
		while (a--){
			vec.push_back(b);
		}
	}
	int l = vec.size();
	bool flagff = true;
	for (int i=0;i*2<=l;i++){
		if (vec[i] != vec[l-i-1]) {
			flagff = false;
			break;
		}
	}
	
	if (flagff){
		std::cout<<0;
		return 0;
	}

	int mincost = (l+1)/2;
	for (int lft=0;lft*2<=l;lft++){
		bool flag = true;
		for (int cc = lft+1;cc*2<=l;cc++){
			if (vec[cc] != vec[l-cc-1]){
				flag = false;
				break;
			}
		}
		if (flag){
			mincost = lft+1;
			break;
		}
	}

	std::cout<<mincost;

	// O(L+L^2)，空间O(L)
}
