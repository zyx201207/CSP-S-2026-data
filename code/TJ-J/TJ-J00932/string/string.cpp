#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n, ans = 0;
	cin >> n;
	vector<pair<int, char> > str(n);
	
	for (int i = 0;i < n; i++){
		cin >> str[i].first >> str[i].second;
	}
	
	int l = 0, r = n-1, temp;
	while (l < n / 2){
		if (str[l].second == str[r].second) {
			temp = str[l].first - str[r].first;
		}
		else {
			if (str[l].first < str[r].first) {
				ans += str[l].first;
			}
			else {
				ans += str[l].second;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
