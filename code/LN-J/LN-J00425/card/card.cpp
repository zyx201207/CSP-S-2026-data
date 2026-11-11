#include <bits/stdc++.h>

int main(void){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin>>n>>m;
	std::vector<int> arr(n);
	for (int i=0;i<n;i++) std::cin>>arr[i];
	std::vector<int> times(m+1);
	for (int i=0;i<n;i++) {
		std::unordered_map<int, int> state;
		std::vector<bool> bs(arr.size()+1);
		for (int k=i;k<arr.size();k++){
			if (state.find(arr[k]) != state.end()){
				for (int j=state[arr[k]]+1;j<=k;j++){
					bs[j]=true;
				}	
			}
			state[arr[k]] = std::min(state[arr[k]], k);
		}
		for (int k=i;k<arr.size();k++){
			if (not bs[k]){
				times[arr[k]]++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		std::cout<<times[i]<<' ';
	}
}

/*std::unordered_map<int, int> times;
std::unordered_map<int, std::multiset<int>> arrhaptime;
std::vector<int> arr;

class AreaGotTree {
	std::unordered_map<int, bool> d;
public:
	void insert(int l, int r){
		for (int i=l;i<=r;i++){
			d[i] = true;
		}
	}

	bool is_in_area(int a) {
		return d[a];
	}
};

void solve(int i, int m){
	if (i != 0){
		arrhaptime[arr[i-1]].erase(i-1);
	}
	std::unordered_map<int, bool> ds;
	std::unordered_map<int, std::multiset<int>::iterator> itsv;
	AreaGotTree ar;
	for (int k=arr.size()-1;k>=i;k--){
		if (arrhaptime[arr[k]].size() > 1){
			if (itsv.find(arr[k]) == itsv.end()){
				itsv[arr[k]] = arrhaptime[arr[k]].end();
				itsv[arr[k]]--;
				itsv[arr[k]]--;
			}else itsv[arr[k]]--;
			ar.insert(*(itsv[arr[k]])+1, k-1);
		}
	}
	for (int k=i;k<arr.size();k++){
		if (not ar.is_in_area(k)) ds[arr[k]]=1;
	}
	for (const std::pair<int, bool>& x: ds){
		times[x.first] += x.second;
	}
}

int main(void){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin>>n>>m;
	arr.resize(n);
	for (int i=0;i<n;i++){
		int x;
		std::cin>>x;
		arrhaptime[x].insert(i);
		arr[i] = x;
	}
	for (int i=0;i<n;i++) solve(i, m);
	for (int i=1;i<=m;i++){
		std::cout<<times[i]<<' ';
	}
}*/
