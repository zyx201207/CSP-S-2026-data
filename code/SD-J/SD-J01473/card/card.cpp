#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int m = 0, n = 0;
	cin >> n >> m; 
	vector<int> cards(n), add(m, -1);
	vector<int> end(m, 0);
	
	for (int i = 0; i < n; i++){
		cin >> cards.at(i);
	}
	
	vector<int> copy;
	
	for (int i = 0; i < n; i++){
		copy = cards;
		int killline = -1;
		if (i != 0) copy.erase(copy.begin(), copy.begin()+i);
		
		for(int j = 0; j < copy.size(); j++){
			if(add.at(copy.at(j)-1) != -1) killline = j-1;
			add.at(copy.at(j)-1) = j;
		}
		
		for (int p = 0; p < m; p++){
			if (add.at(p) > killline) {
				end.at(p) += 1;
			}
		}
	
		for (int i = 0; i < m; i++){
			add.at(i) = -1;
		}
	}
	
	
	for (int i = 0; i < m; i++){
		cout << end.at(i) << " ";
	}
	
	return 0;
}
