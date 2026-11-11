#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(nullptr));
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int n;
	cin >> n >> n >> n >> n >> n;
	while(n--){
		cout << rand() << endl;
	}
	return 0;
}
