#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a != b;
}

string to_bin(int a) {
	vector<char> temp;
	string ans;
	while (a>0) {
		temp.push_back(a%2);
		a /= 2;
	}
	for (int i = (int)temp.size() - 1; i >= 0; i--){
		ans += temp[i];
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	sort(nums.begin(), nums.end(), cmp);
	int ans = nums[0];
	
	for (int i = 0; i < n; i++) {
		//nums[i] = to_bin(nums[i]);
	}
	
	for (int i = 1;i < m; i++){
		ans = ans & nums[i];
	}
	
	cout << ans;
	return 0;
}
