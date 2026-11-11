#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int maxn = 5e5 + 10, maxm = 3e5 + 10;
int ans[maxm], a[maxn];
int sta[maxn];
stack<int> card;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int bg = 1; bg <= n; bg++){
		for(int i = bg; i <= n; i++){
				if(sta[a[i]] == 0){
					card.push(a[i]);
					sta[a[i]] = i;
				}
				else if(sta[a[i]] != 0){
					int tmp = sta[a[i]];
					for(int j = i; j > tmp; j--){
						sta[card.top()] = 0;
						card.pop();
					}
					card.push(a[i]);
					sta[a[i]] = i;
				}

		}
		while(!card.empty()){
			ans[card.top()]++;
			card.pop();
		}
	}
	for(int i = 1; i <= m; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
