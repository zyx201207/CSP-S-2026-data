#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	vector<int> t;
	vector<int> p;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	
	cout << "-1";
	return 0;
}
