#include<bits/stdc++.h>
using namespace std;
deque<string> x, y;
int n, ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int a;
		string c;
		cin >> a >> c;
		while(a--){
			x.push_back(c);
			y.push_front(c);
		}
	}
	int len = n/2 + 1;
	for(int i=1; i <= len; ++i){
		if(x.front() != y.front()){
			x.pop_front();
			y.pop_front();
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
	
*/
