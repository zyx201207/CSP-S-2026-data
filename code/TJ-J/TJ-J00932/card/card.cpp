#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> cards(n+1);
	vector<int> ans(m);
	for (int i = 1; i <= n; i++){
		cin >> cards[i];
	}
	
	for (int i = 1; i <= n; i++) {
		map<int, int> mp;	
		for (int j = 0; j <= m; j++) mp[j] = 0;
		vector<int> ondesk(n+1);
		
		for (int j = i; i <= n; j++){
			if (!mp[cards[j]]) {
				ondesk.push_back(cards[j]);
				mp[cards[j]] = 1;
			}
			else {
				while (cards[j] != ondesk[ondesk.size()-1]) {
					ondesk.pop_back();
				}
			}
		}
		
		for (int j = 0; j < (int)ondesk.size(); j++){
			ans[ondesk[j]]++;
		}
	}
	
	for (int i = 1; i <= (int)ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
