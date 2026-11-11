#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

void tc(){
	int n, k;
	cin >> n >> k;
	cout << rand() % n + 1 << '\n';
	return ;
}

int main(){
	fast;
	srand(time(0));
	int c, t;
	cin >> c >> t;
	while (t --){
		tc();
	}
	return 0;
}