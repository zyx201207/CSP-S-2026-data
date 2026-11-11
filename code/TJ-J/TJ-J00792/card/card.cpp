#include<bits/stdc++.h>
using namespace std;

struct tb{
	int card;
	bool placed;
}cards[300005];

int placed[300005];

bool isPlaced[300005];

int n,m,ans[300005];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> cards[i].card;
		cards[i].placed = ++placed[cards[i].card];
	}
	for(int t = 1; t <= n; ++t) {
		stack<int> s;
		for(int i = t; i <= n; ++i) {
			if(isPlaced[cards[i].card]) {
				while(s.top()!=cards[i].card){
					isPlaced[s.top()] = 0;
					s.pop();
				}
				isPlaced[cards[i].card] = 0;
				s.pop();
			}
			s.push(cards[i].card);
			isPlaced[cards[i].card] = 1;
		}
		memset(isPlaced,0,sizeof(isPlaced));
		while(!s.empty()) {
			++ans[s.top()];
			s.pop();
		}
	}
	for(int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
} 
