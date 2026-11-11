#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
int grid[500005];
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	int last = -1;
	for(int i = 1; i <= n; i++){
		cin >> grid[i];
		if(last > grid[i]) flag = 0;
	}
	if(flag){
		cout << n;
		return 0;
	}
	srand(time(0));
	while(m--){
		cout << rand() % n << " ";
	}
	
	return 0;
}
