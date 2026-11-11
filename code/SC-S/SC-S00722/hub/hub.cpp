#include <random> 
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
std::random_device rd;
mt19937 gen(time(0));
int c, t; 
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	uniform_int_distribution<>d(1, t * t * t * t);
	while(t--){
		cout << d(gen) << '\n';
	}
	return 0;
}
