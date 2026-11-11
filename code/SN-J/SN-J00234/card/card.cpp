#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <stdio.h>

class card{
private:
	int top;
	int ds[510000];
	std::map <int, std::vector <int> > tryfind;
	int find(int x){
		for(const int& i : tryfind[x])
			if(i < top && ds[i] == x)
				return i;
		return -1;
	}
	void Delete(int pos) { top = pos; }
public:
	void clear() { *this = card(); }
	int size() { return top; }
	void insert(int x){
		int pos = find(x);
		if(pos != -1)
			Delete(pos);
		ds[top] = x;;
		tryfind[x].push_back(top);
		top++;
	}
	int at(int pos){
		if(pos < 0 || pos >= top)
			return 2147483647;
		return ds[pos];
	}
	card() : top(0) { 
		tryfind.clear(); 
		memset(ds, 0, sizeof(ds));
	}
};
card a;
std::vector <int> arr(510000), ans(210000);

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
		std::cin >> arr[i];
	
	for(int i = 1; i <= n; i++){
		a.clear();
		for(int pos = i; pos <= n; pos++)
			a.insert(arr[pos]);	
		for(int pos = 0; pos < a.size(); pos++)
			ans[a.at(pos)]++;
	}
	for(int i = 1; i <= m; i++)
		std::cout << ans[i] <<  ' ';
}
