#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

size_t n, m;
int max_result;
vector<int> a;

int main(){
//	cout << "-- Debug --" << endl << "-- Remember to change file read and write --" << endl << endl;
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	a.resize(n);
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	max_result = a[0];
	for (size_t i = 1; i < m; i++)
	cout << (max_result&a[i]);
	
	return 0;
}
