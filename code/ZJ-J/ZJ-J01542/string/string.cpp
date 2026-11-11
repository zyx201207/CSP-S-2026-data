#include <bits/stdc++.h>
using namespace std;

int n, num;
int ans;
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w" , stdout);
	cin >> n;
	int m = n;
	int id = 0, qx, ts;
	while(n --){
		int x;
		char c;
		cin >> x >> c;
		qx = x;
		if(qx == x) ts ++;
		for(int i = id;i < x + id;i ++){
			s += c;
		}
		id = x;
	}
	num = s.size() / 2;
	long long num2 = s.size() - 1;
	for(int i = 0;i < num;i ++){
		if(s[i] != s[num2]){
			ans ++;
			num2 --;
		}
	}
	cout << ans;
	return 0;
}
