#include <bits/stdc++.h>
using namespace std; 
const int maxn = 1011001;
int a[maxn];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	int n, m, flag = 0;
	cin >> n >> m;
	int ans[m+1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int r = 1;
	while(n--){
		vector<int> card;
		for(int i = r; i <= n; i++){
			card.push_back(a[i]);
			for(size_t j = 0; j < card.size(); j++){
				if(card[j] == a[i]) for(int k = 1; k <= i - j; k++) card.pop_back();
				flag = 1;
			}//找相同元素并删除 
			if(flag) card.push_back(a[i]);
		}
		for(size_t i = 0; i <= card.size(); i++) ans[card[i]]++;//统计 
		r++;
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << " "; 
	return 0;
}
